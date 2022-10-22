#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define mkp make_pair
#define fi first
#define se second 
const int M=449;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,t,a[200454];
vector<piii>g[450];
ll ans[200004],ret;
int mp[1000004];
void inc(int x){
	mp[x]++;
	ret+=1ll*x*(1ll*mp[x]*mp[x]-1ll*(mp[x]-1)*(mp[x]-1));
}
void dec(int x){
	ret-=1ll*x*(1ll*mp[x]*mp[x]-1ll*(mp[x]-1)*(mp[x]-1));
	mp[x]--;
}
int main(){
	read(n),read(t);
	for (int i=0;i<n;i++)read(a[i]);
	for (int i=1;i<=t;i++){
		int l,r;read(l),read(r),l--,r--;
		g[r/M].push_back(mkp(mkp(l,r),i)); 
	}
	for (int i=0;i<=n/M;i++){
		sort (g[i].begin(),g[i].end());
		int l=0,r=i*M+M-1;
		for (int j=0;j<=r;j++) inc(a[j]);
		for (int j=0;j<g[i].size();j++){
			while(g[i][j].fi.fi>l) dec(a[l++]);
			while(g[i][j].fi.se<r) dec(a[r--]);
			while(g[i][j].fi.se>r) inc(a[++r]);
			ans[g[i][j].se]=ret;
		}
		if (!g[i].empty())for (int j=g[i][g[i].size()-1].fi.fi;j<=g[i][g[i].size()-1].fi.se;j++) dec(a[j]);
		else for (int j=0;j<=r;j++) dec(a[j]);
	}
	for (int i=1;i<=t;i++) write(ans[i]),puts(""); 
}