fn read_ints() -> Vec<i32> {
    let mut ln = String::new();
    std::io::stdin().read_line(&mut ln).expect("");
    ln.split_whitespace().filter_map(|w| w.parse().ok()).collect()
}

struct SegTreeNode {
    l: usize,
    r: usize,
    lch: usize,
    rch: usize,
    min: i64,
    tag: i64
}

struct SegTree {
    t: Vec<SegTreeNode>,
    root: usize,
    _ql: usize,
    _qr: usize,
    _qv: i64
}

impl SegTree {
    pub fn new(a: &Vec<i64>) -> SegTree {
        let mut ret = SegTree { t: vec![], root: 0, _ql: 0, _qr: 0, _qv: 0 };
        ret.root = ret.build(a, 0, a.len() - 1);
        ret
    }

    pub fn build(&mut self, a: &Vec<i64>, l: usize, r: usize) -> usize {
        let mut node = SegTreeNode {
            l, r,
            lch: 0,
            rch: 0,
            min: std::i64::MIN,
            tag: 0
        };
        if l == r {
            node.min = a[l];
        } else {
            let m = (l + r) >> 1;
            node.lch = self.build(a, l, m);
            node.rch = self.build(a, m + 1, r);
        }
        self.t.push(node);
        let x = self.t.len() - 1;
        self.update_node(x);
        x
    }

    fn apply_tag(&mut self, x: usize, val: i64) {
        self.t[x].min += val;
        self.t[x].tag += val;
    }

    fn push_node(&mut self, x: usize) {
        if self.t[x].tag != 0 && self.t[x].l != self.t[x].r {
            let (lch, rch, val) = (self.t[x].lch, self.t[x].rch, self.t[x].tag);
            self.apply_tag(lch, val);
            self.apply_tag(rch, val);
            self.t[x].tag = 0;
        }
    }

    fn update_node(&mut self, x: usize) {
        self.push_node(x);
        if self.t[x].l != self.t[x].r {
            let (lch_min, rch_min) = (self.t[self.t[x].lch].min, self.t[self.t[x].rch].min);
            self.t[x].min = std::cmp::min(lch_min, rch_min);
        }
    }

    fn range_add_node(&mut self, x: usize) {
        //self.push_node(x);
        if self.t[x].l >= self._ql && self.t[x].r <= self._qr {
            let val = self._qv;
            self.apply_tag(x, val);
            return;
        }
        let (lch, rch) = (self.t[x].lch, self.t[x].rch);
        if self.t[lch].r >= self._ql {
            self.range_add_node(lch);
        }
        if self.t[rch].l <= self._qr {
            self.range_add_node(rch);
        }
        self.update_node(x);
    }

    pub fn range_add(&mut self, l: usize, r: usize, val: i64) {
        if l > r { return; }
        self._ql = l;
        self._qr = r;
        self._qv = val;
        let root = self.root;
        self.range_add_node(root);
    }

    fn find_zero_node(&mut self, x: usize) -> Option<usize> {
        self.push_node(x);
        //println!("node = [{}, {}] min = {}", self.t[x].l, self.t[x].r, self.t[x].min);
        let (lch, rch) = (self.t[x].lch, self.t[x].rch);
        if lch == rch {
            if self.t[x].min == 0 {
                return Some(self.t[x].l);
            }
        } else {
            if self.t[lch].min <= 0 {
                if let Some(_x) = self.find_zero_node(lch) {
                    return Some(_x);
                }
            }
            if self.t[rch].min <= 0 {
                if let Some(_x) = self.find_zero_node(rch) {
                    return Some(_x);
                }
            }
        }
        None
    }

    pub fn find_zero(&mut self) -> Option<usize> {
        let root = self.root;
        self.find_zero_node(root)
    }
}

impl std::fmt::Debug for SegTree {
    fn fmt(&self, f: &mut std::fmt::Formatter) -> std::fmt::Result {
        for (id, ref el) in self.t.iter().enumerate() {
            writeln!(f, "{} [{}, {}] min {} tag {} lch {} rch {}",
                id, el.l, el.r, el.min, el.tag, el.lch, el.rch)?
        }
        Ok(())
    }
}

fn main() {
    let (n, q): (usize, i32);
    if let [_n, _q] = read_ints()[..] { n = _n as usize; q = _q; } else { panic!("> <"); }

    let mut a = read_ints();
    assert_eq!(n, a.len());

    let mut b: Vec<i64> = vec![];
    let mut sum = 0i64;
    for i in 0..n {
        b.push(sum - a[i] as i64);
        sum += a[i] as i64;
    }

    let mut sgt = SegTree::new(&b);

    for _ in 0..q {
        let (p, v): (usize, i64);
        if let [_p, _v] = read_ints()[..] { p = _p as usize - 1; v = _v as i64; } else { panic!("> <"); }
        let delta = v - a[p] as i64;
        a[p] = v as i32;
        sgt.range_add(p, p, -delta);
        sgt.range_add(p + 1, n - 1, delta);

        if a[0] == 0 {
            println!("1");
        } else {
            let id = sgt.find_zero();
            if let Some(_id) = id {
                println!("{}", _id + 1);
            } else {
                println!("-1");
            }
        }
        //println!("{:?}", sgt);
    }
}