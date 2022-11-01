#include<bits/stdc++.h>
#define LL long long
#define pb push_back
using namespace std;
const int N=1e5+5;
struct node{int x,t;}a[N];
int n,k;LL ans;bool usd[N];
vector<int>v;
bool cmp(node a,node b){return a.t>b.t;}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++)scanf("%d",&a[i].t);
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
		if(!usd[a[i].x])usd[a[i].x]=true,k--;else v.pb(a[i].t);
	reverse(v.begin(),v.end());
	for(int i=1;i<=k;i++)ans+=(LL)v[i-1];
	printf("%lld\n",ans);
	return 0;
}