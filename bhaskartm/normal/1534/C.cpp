#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
const int N=4e5+5;
const int MOD=1e9+7;
int arr[N];
int po[N];
int n; 



int parent[N];
int sz[N];
int tot=0;
void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
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
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
        tot--;
    }
}


 
main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	po[0]=1;
	for(int i=1; i<N; i++){
		po[i]=(2*po[i-1])%MOD;
	}
	cin>>t;
	while(t--){
		cin>>n;
		int a[n];
		int b[n];
		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			cin>>b[i];
		}
		tot=n;
		for(int i=1; i<=n; i++){
			make_set(i);
		}
		for(int i=0; i<n; i++){
			union_sets(a[i], b[i]);
		}
		cout<<po[tot]<<endl;
	}
	return 0;
}