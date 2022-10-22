#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=0x3f3f3f3fll;
const ll mod=998244353ll;
int n,m;
vector<int> v[N];
int occ[N];
int pre[N];
int a[N];
int main(){
	ios::sync_with_stdio(0);
	int i,j,k;
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==m) occ[i]=1;
	}
	for(i=1;i<=n;i++) occ[i]+=occ[i-1];
	for(i=1;i<=n;i++){
		v[a[i]].push_back(occ[pre[a[i]]]-occ[i]);
		v[a[i]].push_back(1);
		pre[a[i]]=i;
	}
	int ans=occ[n];
	for(i=1;i<N;i++){
		if(i==m) continue;
		int cur=0;
		for(j=0;j<v[i].size();j++){
			cur+=v[i][j];
			cur=max(cur,0);
			ans=max(ans,cur+occ[n]);
		}
	}
	cout<<ans;
	return 0;
}