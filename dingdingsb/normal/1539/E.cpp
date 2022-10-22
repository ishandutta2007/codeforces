// Problem: E. Game with Cards
// Contest: Codeforces - Codeforces Round #727 (Div. 2)
// URL: https://codeforces.ml/contest/1539/problem/E
// Memory Limit: 256 MB
// Time Limit: 2500 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,m;
int k[N],al,ar,bl,br;
int lst[N][2];
#define fi first
#define se second
void out(int x,int op){
	if(!x)return;
	out(lst[x][op],op^1);
	for(int i=lst[x][op]+1;i<=x;i++)
		putchar('0'+op),putchar(' ');
}
signed main(){
	scanf("%lld%lld",&n,&m);
	set<pair<int,int>>s[2];
	scanf("%lld%lld%lld%lld%lld",&k[1],&al,&ar,&bl,&br);
	if(al<=k[1]&&k[1]<=ar&&!bl)s[0].insert({0,0});
	if(bl<=k[1]&&k[1]<=br&&!al)s[1].insert({0,0});
	for(int i=2;i<=n;i++){
		scanf("%lld%lld%lld%lld%lld",&k[i],&al,&ar,&bl,&br);
		int a=s[0].size(),b=s[1].size();
		if(b)s[0].insert({k[i-1],i-1});
		if(a)s[1].insert({k[i-1],i-1});
		if(al<=k[i]&&k[i]<=ar){
			while(s[0].size()&&s[0].begin()->first<bl)
				s[0].erase(s[0].begin());
			while(s[0].size()&&s[0].rbegin()->first>br)
				s[0].erase(*s[0].rbegin());
		}else s[0].clear();
		
		if(bl<=k[i]&&k[i]<=br){
			while(s[1].size()&&s[1].begin()->first<al)
				s[1].erase(s[1].begin());
			while(s[1].size()&&s[1].rbegin()->first>ar)
				s[1].erase(*s[1].rbegin());
		}else s[1].clear();
		
		if(s[0].size())lst[i][0]=s[0].begin()->second;
		if(s[1].size())lst[i][1]=s[1].begin()->second;
	}
	if(s[0].size())puts("Yes"),out(n,0);
	else if(s[1].size())puts("Yes"),out(n,1);
	else puts("No");
}