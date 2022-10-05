 
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pd;
typedef complex<ld> cd;
typedef vector<int> vi;
typedef vector<ll> vll;

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

int main() { FAST
    int m,n;
    cin >> m >> n;
    vll a(m, 0);
    vll b(n, 0);
    for (int i = 0; i<m;i++) cin >> a[i];    
    for (int i = 0; i<n;i++) cin >> b[i];
    
    ll out = 0;
    
    vector<vll> edges = vector<vll>();
    for (int i = 0; i < m; i++){
        int c;
        cin >> c;
        for(int j = 0; j < c; j++){
            int d;
            cin >> d;
            d -= 1;
            vll add(3,0);
            add[0] = -a[i] - b[d];
            out -= add[0];
            add[1] = i;
            add[2] = d + m;
            edges.pb(add);
        }
    }
    
    sort(edges.begin(), edges.end());
    //reverse(edges.begin(), edges.end());
    
    UF unionfind = UF(m + n);
    
    for (auto edge : edges){
        int c = edge[0];
        int u = edge[1];
        int v = edge[2];
        
        //cout << c << " " << u << " " << v << '\n';
        
        if (unionfind.find(u) != unionfind.find(v)){
            out += c;
            unionfind.join(u,v);
        }
    }
    
    
    
    cout << out;
}