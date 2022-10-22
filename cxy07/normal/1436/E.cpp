    //Code By CXY07
    #include<bits/stdc++.h>
    using namespace std;
     
    //#define FILE
    //#define int long long
    //#define ull unsigned long long
    #define LL long long
    #define pii pair<int,int>
    #define mp make_pair
    #define pb push_back
    #define fst first
    #define scd second
    #define inv(x) qpow((x),mod - 2)
    #define lowbit(x) ((x) & (-(x)))
    #define vec vector
     
    const int MAXN = 5e5 + 10;
    const int INF = 2e9;
    const double PI = acos(-1);
    const double eps = 1e-6;
    //const int mod = 1e9 + 7;
    //const int mod = 998244353;
    //const int G = 3;
    //const int base = 131;
     
    struct Q {
    	int l, r, id;
    	Q(int _l = 0, int _r = 0, int _id = 0) : l(_l), r(_r), id(_id) {}
    } q[MAXN];
     
    int n, m, qcnt, Mex;
    int blk, siz, bl[MAXN];
    int a[MAXN], ans[MAXN];
    int cnt[MAXN], now = 1, qpos[MAXN];
    vector<int> app[MAXN];
     
    template<typename T> inline void read(T &a) {
    	a = 0; char c = getchar(); int f = 1;
    	while(c < '0' || c > '9') {if(c == '-') f = -1; c = getchar();}
    	while(c >= '0' && c <= '9') {a = a * 10 + (c ^ 48); c = getchar();}
    	a *= f;
    }
     
    inline bool cmp(Q a,Q b) {return ((bl[a.l] ^ bl[b.l]) ? bl[a.l] < bl[b.l] : ((bl[a.l] & 1) ? a.r < b.r : a.r > b.r));}
     
    inline void add(int i) {
    	i = a[i];
    	if(i > n + 1) return;
    	cnt[i]++;
    	if(now == i && cnt[i] > 0) {
    		for(register int p = i;p <= n + 1; ++p) {
    			if(!cnt[p]) {
    				now = p;
    				break;
    			}
    		}
    	}
    }
     
    inline void del(int i) {
    	i = a[i];
    	if(i > n + 1) return;
    	cnt[i]--;
    	if(!cnt[i]) now = min(now,i);
    }
     
    signed main () {
    #ifdef FILE
    	freopen(".in","r",stdin);
    	freopen(".out","w",stdout);
    #endif
    	read(n);
    	for(int i = 1; i <= n; ++i) {
    		read(a[i]);
    		app[a[i]].pb(i);
    	}
    	siz = sqrt(n);
    	blk = ceil((double) n / siz);
    	for(register int i = 1;i <= blk; ++i)
    		for(register int j = (i - 1) * siz + 1;j <= i * siz; ++j)
    			bl[j] = i;
    	a[0] = n + 2;
    	for(int i = 1; i <= n + 1; ++i) {
    		int pre = 0;
    		for(auto pos : app[i]) {
    			if(pos - 1 >= pre + 1) {
    				qcnt++;
    				q[qcnt] = Q(pre + 1, pos - 1, qcnt);
    			}
    			pre = pos;
    		}
    		if(n >= pre + 1) {
    			++qcnt;
    			q[qcnt] = Q(pre + 1, n, qcnt);
    		}
    		qpos[i] = qcnt;
    	}
    	int l = 1,r = 0;
    	sort(q + 1,q + qcnt + 1,cmp);
    	for(register int i = 1,L,R;i <= qcnt; ++i) {
    		L = q[i].l; R = q[i].r;
    		while(l < L) del(l++);
    		while(l > L) add(--l);
    		while(r < R) add(++r);
    		while(r > R) del(r--);
    		ans[q[i].id] = now;
    	}
    	for(int i = 1; i <= n + 1; ++i) {
    		bool flag = false;
    		for(int p = qpos[i - 1] + 1; p <= qpos[i]; ++p) 
    			if(ans[p] == i) {flag = true; break;}
    		if(!flag) {
    			Mex = i;
    			break;
    		}
    	}
    	if(!Mex) Mex = n + 2;
    	cout << Mex << endl;
    	return 0;
    }