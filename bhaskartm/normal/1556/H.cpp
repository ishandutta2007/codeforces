#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define T long double

const int N=55;
const int M=1e9;

int n, k;
int d[N];
int deg[N];


int w[N][N];


int p[N];
int sz[N];

void make_set(int v) {
    p[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == p[v])
        return v;
    return p[v] = find_set(p[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            swap(a, b);
        p[b] = a;
        sz[a] += sz[b];
    }
}

 
 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mt19937 rnd(time(NULL));
	cin>>n>>k;
	
	
	
	for(int i=1; i<=k; i++){
		cin>>d[i];
	}
	
	for(int i=k+1; i<=n; i++){
		d[i]=1e9;
	}
	
	for(int i=1; i<n; i++){
		for(int j=i+1; j<=n; j++){
			cin>>w[i][j];
			w[j][i]=w[i][j];
		}
	}
	
	T temp=1e4;
	int tsteps=1000000;
	T red=0.9999;
	
	int ans=0;
	vector<pair<int, int>>vec;
	for(int i=1; i<n; i++){
		ans+=w[i][n];
		vec.pb({i, n});
		deg[i]++;
		deg[n]++;
	}
	
	int mini=1e9;
	
	for(int jj=0; jj<tsteps; jj++){
		temp=temp*red;
		int x=rnd();
		x=abs(x);
		x=(x%(n-1));
		
		for(int i=1; i<=n; i++){
			make_set(i);
		}
		
		for(int i=0; i<n-1; i++){
			if(i==x){
				continue;
			}
			union_sets(vec[i].f, vec[i].s);
		}
		
		int ou=vec[x].f;
		int ov=vec[x].s;
		deg[ou]--;
		deg[ov]--;
		int nu=rnd();
		nu=abs(nu);
		nu=(nu%n)+1;
		int nv=rnd();
		nv=abs(nv);
		nv=(nv%n)+1;
		while(find_set(nu)==find_set(nv) || deg[nu]==d[nu] || deg[nv]==d[nv]){
			nu=rnd();
			nu=abs(nu);
			nu=(nu%n)+1;
			nv=rnd();
			nv=abs(nv);
			nv=(nv%n)+1;
		}
		int nans=ans-w[ou][ov]+w[nu][nv];
		int ran=rnd();
		ran=abs(ran);
		ran=(ran%M);
		T pr=(ran*1.0/M);
		if((exp(((ans-nans)*1.0)/temp))>pr){
			vec[x]={nu, nv};
			ans=nans;
			deg[nu]++;
			deg[nv]++;
		}
		else{
			deg[ou]++;
			deg[ov]++;
		}
		mini=min(mini, ans);
		
	}
	
	cout<<mini<<endl;
	
	
	return 0;
}