// Problem: D. PriceFixed
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.ml/contest/1539/problem/D
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n;
struct node{
	int a,b;
	bool operator<(const node&x)const{
		return b>x.b;
	}
}p[N];
signed main(){
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld%lld",&p[i].a,&p[i].b);
	sort(p+1,p+1+n);
	int res=0,ans=0;int l=1,r=n;
	while(l<=r){
		if(p[l].a+res<=p[r].b)
			res+=p[l].a,ans+=p[l].a*2,l++;
		else{
			int _=p[r].b-res;
			res=p[r].b;ans+=_*2;
			p[l].a-=_;
		}
		while(l<=r&&p[r].b<=res)
			ans+=p[r].a,res+=p[r].a,
			r--;
	}
	printf("%lld",ans);
}