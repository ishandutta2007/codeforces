#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'

const int MOD=998244353;
int N=0;



int add(int x, int y)
{
	return (x + y) % MOD;
}
 
int sub(int x, int y)
{
	return add(x, MOD - y);
}
 
int mul(int x, int y)
{
	return (x * 1ll * y) % MOD;
}
 
int binpow(int x, int y)
{
	int z = 1;
	while(y > 0)
	{
		if(y % 2 == 1)
			z = mul(z, x);
		x = mul(x, x);
		y /= 2;
	}
	return z;
}
 
int inv(int x)
{
	return binpow(x, MOD - 2);
}
 
const int M=250005;

 
int fact[M];
int ifact[M];
 
int C(int n, int k)
{
	return mul(fact[n], (mul(ifact[k], ifact[n - k])));
}
 
int modpow(int a, int  b) {a %= MOD; int res = 1; while (b) {if (b & 1)res = mul(res, a); a = mul(a, a); b >>= 1;} return res;}
int modinv(int  a) {return modpow(a, MOD - 2);}
 
struct NTT {
    int root, root_1, root_pw = 1, c;
    NTT(int n, bool init = true) {
        while(root_pw < n) root_pw <<= 1, N++;
        if (init) {
            vector<int> pf;
            int n = MOD - 1, phi = n;
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    pf.push_back(i);
                    while (n % i == 0) n /= i;
                }
            }
            if (n > 1) pf.push_back(n);
            for (int r = 2; r <= phi; r++) {
                bool ok = true;
                for (auto &x : pf) {
                    if (modpow(r, phi / x) == 1)
                    {ok = false; break;}
                }
                if (ok) {
                    c = (MOD - 1) >> N;
                    root = modpow(r, c), root_1 = modinv(root); 
                    break;
                }
            }
        }
    }
    void transform(vector<int> & a, bool invert) {
        int n = a.size();
        assert(n <= root_pw);
        for (int i = 1, j = 0; i < n; i++) {
            int bit = n >> 1;
            for (; j & bit; bit >>= 1)
                j ^= bit;
            j ^= bit;
 
            if (i < j)
                swap(a[i], a[j]);
        }
        for (int len = 2; len <= n; len <<= 1) {
            int wlen = invert ? root_1 : root;
            for (int i = len; i < root_pw; i <<= 1)
                wlen = (int)(1LL * wlen * wlen % MOD);
            for (int i = 0; i < n; i += len) {
                int w = 1;
                for (int j = 0; j < len / 2; j++) {
                    int u = a[i + j], v = (int)(1LL * a[i + j + len / 2] * w % MOD);
                    a[i + j] = u + v < MOD ? u + v : u + v - MOD;
                    a[i + j + len / 2] = u - v >= 0 ? u - v : u - v + MOD;
                    w = (int)(1LL * w * wlen % MOD);
                }
            }
        }
        if (invert) {
            int n_1 = modinv(n);
            for (int & x : a)
                x = (int)(1LL * x * n_1 % MOD);
        }
    }
    vector<int> multiply(vector<int> const& a, vector<int> const& b) {
        vector<int> fa(a), fb(b);
        int n = 1, total = a.size() + b.size();
        while (n < total) n <<= 1;
        fa.resize(n);
        fb.resize(n);
        transform(fa, false); transform(fb, false);
        for (int i = 0; i < n; i++)
            fa[i] = (fb[i] * 1LL * fa[i]) % MOD;
        transform(fa, true);
        fa.resize(total - 1);
        while(!fa.empty() && fa.back() == 0) fa.pop_back();
        return fa;
    }
} ntt(M);


vector<vector<int>>adj;

int n;
vector<vector<int>>vec;


vector<int> fu(int l, int r){
	if(l==r){
		return vec[l];
	}
	int mid=(l+r)/2;
	vector<int>vec1=fu(l, mid);
	vector<int>vec2=fu(mid+1, r);
	
	vector<int>ne=ntt.multiply(vec1, vec2);
	
	
	return ne;
}

 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	fact[0]=1;
	for(int i=1; i<M; i++){
		fact[i]=(fact[i-1]*i)%MOD;
	}
	for(int i=0; i<M; i++){
		ifact[i]=inv(fact[i]);
	}
	
	
	cin>>n;
	
	adj.resize(n+1);
	
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	
	
	for(int i=1; i<=n; i++){
		int val=adj[i].size();
		if(i!=1){
			val--;
		}
		vector<int>ne;
		ne.pb(1);
		ne.pb(val);
		vec.pb(ne);
	}
	
	
	vector<int>res=fu(0, n-1);
	while(1){
		int sz=res.size();
		if(sz==n){
			break;
		}
		res.pb(0);
	}
	int ans=0;
	int sn=1;
	for(int i=0; i<n; i++){
		
		ans=(((ans+(sn*fact[n-i]*res[i]))%MOD)+MOD)%MOD;
		sn=sn*(-1);
	}
	cout<<ans<<endl;
	
	return 0;
}