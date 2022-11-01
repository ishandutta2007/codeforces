#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pii pair<int,int>
using namespace std;
int n,lg;
vector<pii>Ans;
void solve(int l,int r){
	if(l==r)return;
	int mid=(l+r)>>1;
	solve(l,mid);solve(mid+1,r);
	for(int i=l;i<=mid;i++)Ans.pb(pii(i,i-l+mid+1));
}
int main(){
	scanf("%d",&n);
	while((1<<lg)<=n)lg++;lg--;
	solve(1,(1<<lg));solve(n-(1<<lg)+1,n);
	printf("%d\n",(int)Ans.size());
	for(auto x:Ans)printf("%d %d\n",x.first,x.second);
	return 0;
}