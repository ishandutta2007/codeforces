#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pli;
#define mkp make_pair
#define fi first
#define se second
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void readi(ll &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,k;
ll a[200004];
int b[200004];
ll now[200004];
short check(ll x){
	priority_queue <pli,vector<pli>,greater<pli> > q;
	for (int i=1;i<=n;i++){
		now[i]=a[i];
		q.push(mkp(a[i]/b[i],i));
	}
	for (int i=1;i<=k-1;i++){
		pli u=q.top();q.pop(); 
		now[u.se]+=x;
		q.push(mkp(now[u.se]/b[u.se],u.se));
		u=q.top(); 
		if (u.fi<i) return 0;
	}
	return 1;
}
int main(){
	read(n),read(k);
	for (int i=1;i<=n;i++) readi(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	ll l=-1,r=4e12;
	while (r>l+1){
		ll mid=(l+r)/2;
		if (check(mid)) r=mid;
		else l=mid;
	}
	if (check(r)) write(r);
	else puts("-1");
}