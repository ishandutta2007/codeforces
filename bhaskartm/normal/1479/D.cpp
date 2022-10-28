#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")


#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=300005;
const int M=12000005;


int ID=0;
int root[2*N+5];
int l[M];
int r[M];
long long int t[M];
 

 
int update(int pos, int prev, int tl, int tr, long long int num){
	int id=++ID;
	if(tl==tr){
		t[id]=t[prev]^num;
		return id;
	}
	int tm=(tl+tr)/2;
	l[id]=l[prev];
	r[id]=r[prev];
	if(pos<=tm){
		l[id]=update(pos, l[id], tl, tm, num);
	}
	else{
		r[id]=update(pos, r[id], tm+1, tr, num);
	}
	t[id]=t[l[id]]^t[r[id]];
	return id;
}
 
 
long long int query(int id, int id2, int le, int ri, int tl, int tr){
	if(le>ri){
		return 0;
	}
	if(le==tl && ri==tr){
		return t[id]^t[id2];
	}
	int tm=((tl+tr)/2);
	return (query(l[id], l[id2], le, min(ri, tm), tl, tm))^(query(r[id], r[id2], max(le, tm+1), ri, tm+1, tr));
}



long long int val[N]; 
vector<vector<int>>adj;
int arr[N];
vector<pair<int, int>>pos;
int ind=0;

int n, q;



void dfsx(int v, int p){
	root[ind+1]=update(arr[v], root[ind], 1, n, val[arr[v]]);
	ind++;
	pos.pb({v, ind});
	for(auto u:adj[v]){
		if(u==p){
			continue;
		}
		dfsx(u, v);
	}
	root[ind+1]=update(arr[v], root[ind], 1, n, val[arr[v]]);
	ind++;
}



// lca begin


int lll;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

void dfs(int v, int p){
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i = 1; i <= lll; ++i){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for (int u : adj[v]) {
        if (u != p){
            dfs(u, v);
        }
    }
    tout[v] = ++timer;
}

bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = lll; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1);
    tout.resize(n+1);
    timer = 0;
    lll = ceil(log2(n+1));
    up.assign(n+1, vector<int>(lll + 1));
    dfs(root, root);
}


//lca end




int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	mt19937_64 rnd(time(NULL));
	for(int i=1; i<N; i++){
		val[i]=abs(int(rnd()));
	}
	
	cin>>n>>q;
	adj.resize(n+1);
	
	for(int i=1; i<=n; i++){
		cin>>arr[i];
	}
	
	for(int i=0; i<n-1; i++){
		int u, v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	dfsx(1, 0);
	sort(pos.begin(), pos.end());
	preprocess(1);
	
	while(q--){
		int u, v, le, ri;
		cin>>u>>v>>le>>ri;
		int lc=lca(u, v);
		long long int valc=0;
		if(arr[lc]>=le && arr[lc]<=ri){
			valc=val[arr[lc]];
		}
		
		
		long long int q1=(query(root[pos[u-1].s], root[pos[v-1].s], le, ri, 1, n));
	
		long long int uc=valc^q1;
		
		if(uc==0){
			cout<<-1<<endl;
			continue;
		}
		while(le!=ri){
			int mid=(le+ri)/2;
			long long int valcc=0;
			if(arr[lc]>=le && arr[lc]<=mid){
				valcc=val[arr[lc]];
			}
			long long int uc=valcc^(query(root[pos[u-1].s],root[pos[v-1].s], le, mid, 1, n));
			if(uc==0){
				le=mid+1;
			}
			else{
				ri=mid;
			}
		}
		cout<<le<<endl;
	}
	
	return 0;
}