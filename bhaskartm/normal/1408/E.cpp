#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'


int parent[200005];
int size[200005];

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
	int n, m;
	cin>>m>>n;
	int a[m+1];
	int b[n+1];
	
	for(int i=1; i<=m; i++){
		cin>>a[i];
	}
	for(int i=1; i<=n; i++){
		cin>>b[i];
	}
	vector<pair<int, pair<int, int>>>v;
	int tot=0;
	for(int i=1; i<=m; i++){
		int sz;
		cin>>sz;
		for(int j=0; j<sz; j++){
			int x;
			cin>>x;
			v.pb({a[i]+b[x], {i, m+x}});
			tot+=(a[i]+b[x]);
		}
	}
	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());
	
	for(int i=1; i<=n+m; i++){
		make_set(i);
	}
	int ans=0;
	for(auto u:v){
		if(find_set(u.s.f)==find_set(u.s.s)){
			continue;
		}
		else{
			union_sets(u.s.f, u.s.s);
			ans+=(u.f);
		}
	}
	cout<<tot-ans;
	
	return 0;
}