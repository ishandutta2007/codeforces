;
var inp = [];
var out = [];
var lines;
var lineCounter = 0;
var readline = function () { return lines[lineCounter++]; };
var writeline = function (line) { return out.push(String(line)); };
process.stdin.on('data', function (c) { return inp.push(c); });
process.stdin.on('end', function () {
    lines = inp.join('').split('\n');
    myMain();
    console.log(out.join('\n'));
});
var DSU = /** @class */ (function () {
    function DSU(sz) {
        this.par = Array.from({ length: sz }, function (id) { return -1; });
        this.compCnt = sz;
    }
    DSU.prototype.findset = function (u) {
        var p = u;
        while (this.par[p] >= 0) {
            p = this.par[p];
        }
        while (this.par[u] >= 0) {
            var tmp = this.par[u];
            this.par[u] = p;
            u = tmp;
        }
        return p;
    };
    DSU.prototype.join = function (u, v) {
        var _a;
        u = this.findset(u);
        v = this.findset(v);
        if (u === v)
            return;
        if (-this.par[u] < -this.par[v]) {
            _a = [v, u], u = _a[0], v = _a[1];
        }
        this.par[u] += this.par[v];
        this.par[v] = u;
        --this.compCnt;
    };
    return DSU;
}());
function myMain() {
    var ntest = +readline();
    for (var testcase = 0; testcase < ntest; ++testcase) {
        var n = +readline();
        var s = readline().trim();
        var dsu = new DSU(2 * n);
        var stk = [];
        for (var i = 0; i < 2 * n; ++i) {
            if (s[i] === '(') {
                stk.push(i);
            }
            else {
                dsu.join(stk.pop(), i);
                if (i + 1 < 2 * n && s[i + 1] === '(') {
                    dsu.join(i, i + 1);
                }
            }
        }
        writeline(dsu.compCnt);
    }
}