#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=1e9+7;



int parent[500005];
int size[500005];
int sp[500005];

void make_set(int v) {
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        if(sp[a] || sp[b]){
        	sp[a]=1;
        }
    }
}




main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin>>n>>m;
	int ans=1;
	vector<int>vec;
	for(int i=0; i<n; i++){
		int k;
		cin>>k;
		if(k==1){
			int x;
			cin>>x;
			if(size[x]==0){
				make_set(x);
				sp[x]=1;
				ans=(ans*2)%N;
				vec.pb(i);
			}
			else{
				if(sp[find_set(x)]==1){
					continue;
				}
				else{
					sp[find_set(x)]=1;
					ans=(ans*2)%N;
					vec.pb(i);
				}
			}
		}
		else{
			int u, v;
			cin>>u>>v;
			if(size[u]==0){
				make_set(u);
			}
			if(size[v]==0){
				make_set(v);
			}
			int p1=find_set(u);
			int p2=find_set(v);
			
			if(p1==p2){
				continue;
			}
			if(sp[p1] && sp[p2]){
				continue;
			}
			else{
				ans=(ans*2)%N;
				union_sets(u, v);
				vec.pb(i);
			}
		}
	}
	cout<<ans<<" "<<vec.size()<<endl;
	for(auto u:vec){
		cout<<u+1<<" ";
	}
	return 0;
}