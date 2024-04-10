#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005
struct node{
    int x, y, z;
    node(){}
    node(int xx, int yy, int zz){x = xx, y = yy, z = zz;}
    bool operator < (const node other) const {
        return x < other.x;
    }
    node flip(int a, int b, int c, int sx, int sy, int sz){
        if(a == 0) x = sx-x;
        if(b == 0) y = sy-y;
        if(c == 0) z = sz-z;
        return node(x, y, z);
    }
};
struct querie{
    node pt;
    int index;
    querie(){}
    querie(int xx, int yy, int zz, int id){pt= node(xx, yy, zz), index = id;}
    querie(node nd, int id){pt = nd, index = id;}
    bool operator < (const querie other) const {
        return pt < other.pt;
    }
};
template<class T> struct Seg { 
	const T ID = 1e9; // comb(ID,b) must equal b, and maximum is less than 1e9
	T comb(T a, T b) { return min(a, b); } 
	int n; vector<T> seg;
	void init(int _n) { n = _n; seg.assign(2*n, ID); }
	void pull(int p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
	void upd(int p, T value) {	// set value at position p
		seg[p += n] = value;
		for (p /= 2; p; p /= 2) pull(p);
	}
	T query(int l, int r) {	 // sum on interval [l, r]
		T ra = ID, rb = ID; 
		for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
			if (l&1) ra = comb(ra,seg[l++]);
			if (r&1) rb = comb(seg[--r],rb);
		}
		return comb(ra,rb);
	}
};
vector<querie> q[2][2][2];
node points[MAXN];
int xmax, ymax, zmax, n, m, k;
int xl = MAXN, xr = -MAXN, yl = MAXN, yr = -MAXN, zl = MAXN, zr = -MAXN;
string ans[MAXN];
vector<node> ttp[4*MAXN];
bool inRange(int x, int y, int z){
    return x >= xl && x <=xr && y >= yl && y <= yr && z >= zl && z <= zr;
}
bool inRange(node point){
    int x = point.x, y = point.y, z = point.z;
    return inRange(x, y, z);
}
int sgn(int x) {return x >= 0;}
void solve(vector<node> tp, vector<querie> qq){
    sort(qq.begin(),qq.end());
    for(int i = 0; i<4*MAXN; i++) ttp[i].clear();
    for(auto p : tp){
        ttp[p.x+MAXN].push_back(p);
    }
    Seg<int> seg;
    seg.init(4*MAXN);
    int prev = xl+MAXN-1;
    for(auto e : qq){
        if(inRange(e.pt)){
            ans[e.index] = "OPEN";
            continue;
        }
        for(int i = prev+1; i<=e.pt.x+MAXN; i++){
            for(auto nd : ttp[i]){
                if(seg.query(nd.y+MAXN,nd.y+MAXN)>nd.z+MAXN && nd.z+MAXN >= zl+MAXN) seg.upd(nd.y+MAXN, nd.z+MAXN);
            }
        }
        prev = e.pt.x+MAXN;
        if(seg.query(yl+MAXN, e.pt.y+MAXN) > e.pt.z+MAXN){
            ans[e.index] = "UNKNOWN";
        }
        else ans[e.index] = "CLOSED";
    }
    
}

int main(){
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> xmax >> ymax >> zmax >> n >> m >> k;
    for(int i = 0; i<n; i++){
        int x, y, z; cin >> x >> y >> z;
        xl = min(xl, x);
        xr = max(xr, x);
        yl = min(yl, y);
        yr = max(yr, y);
        zl = min(zl, z);
        zr = max(zr, z);
    }
    for(int i = 0; i<m; i++){
        int xx, yy, zz; cin >> xx >> yy >> zz;
        node tmp(xx, yy, zz);
        points[i] = tmp;
        if(inRange(tmp)){
            cout << "INCORRECT" << endl;
            exit(0);
        }
    }
    cout << "CORRECT" << endl;
    for(int i = 0; i<k; i++){
        int xx, yy, zz; cin >> xx >> yy >> zz;
        if(xl <= xx && xx <= xr) xx = xr;
        if(yl <= yy && yy <= yr) yy = yr;
        if(zl <= zz && zz <= zr) zz = zr;
        node temp(xx, yy, zz);
        querie qq(temp, i);
        q[sgn(xx-xr)][sgn(yy-yr)][sgn(zz-zr)].push_back(querie(temp.flip(sgn(xx-xr), sgn(yy-yr), sgn(zz-zr), xl+xr, yl+yr, zl+zr), i));
    }
    for(int a = 0; a<2; a++){
        for(int b = 0; b<2; b++){
            for(int c = 0; c<2; c++){
                vector<node> tp(m);
                for(int i = 0; i<m; i++){
                    tp[i] = points[i].flip(a, b, c, xl+xr, yl+yr, zl+zr);
                    points[i].flip(a, b, c, xl+xr, yl+yr, zl+zr);
                }
                solve(tp, q[a][b][c]);
            }
        }
    }
    for(int i = 0; i<k; i++){
        cout << ans[i] << endl;
    }
}