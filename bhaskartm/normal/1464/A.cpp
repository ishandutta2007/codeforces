#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int parent[100005];
int size[100005];

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
    }
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n, m;
		cin>>n>>m;
		for(int i=1; i<=n; i++){
			make_set(i);
		}
		int ans=0;
		for(int i=0; i<m; i++){
			int x, y;
			cin>>x>>y;
			if(x==y){
				continue;
			}
			else{
				ans++;
			}
			if(find_set(x)==find_set(y)){
				ans++;
			}
			union_sets(x, y);
		}
		cout<<ans<<endl;
		
	}
	return 0;
}