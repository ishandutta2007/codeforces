#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define M 1000000007
#define fr first
#define sc second
#define vc vector
vc<int> v[100009];
set<int> s;
int a[100009];
int dfs(int z){
	int c=0;
	s.insert(z);
	for(int i=0;i<v[z].size();i++){
		if(s.find(v[z][i])!=s.end()) continue;
		c+=dfs(v[z][i]);
	}
	if(c==0)c++;
	a[z]=c;
	return c;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n,t;
    cin>>n;
    for(int i=2;i<=n;i++){
    	cin>>t;
    	v[i].pb(t);
    	v[t].pb(i);
    }
    dfs(1);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
    	cout<<a[i]<<" ";
    }
}