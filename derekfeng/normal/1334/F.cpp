#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	int res=1;char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	if (ch=='-') res=-1,ch=getchar();
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar()); 
	x*=res;
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0'); 
}
void wwrite(ll x){
	if (x<0) putchar('-'),write(-x);
	else write(x);
}
int n,m,a[500005],b[500005],c[500005];
ll dat[500005];
void Add(int id,ll x){while (id)dat[id]+=x,id-=(id&-id);}
void Qry(int l,int r,ll x){Add(l-1,-x),Add(r,x);}
ll Ans(int id){ll ret=0;while(id<=m+1)ret+=dat[id],id+=(id&-id);return ret;}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(c[i]);
	read(m);
	for (int i=1;i<=m;i++) read(b[i]);
	Add(m+1,1e18);
	Add(1,-(1000000000000000000));
	for (int i=1;i<=n;i++){
		int l=lower_bound(b+1,b+1+m,a[i])-b;
		if (l<=m && b[l]==a[i]){
			ll v1=Ans(l),v2=Ans(l+1),v3=v2+min(0,c[i]);
			Qry(l+1,l+1,-v2),Qry(l+1,l+1,min(v1,v3));
			Add(l,c[i]);
			if (l<m && c[i]<0) Qry(l+2,m+1,c[i]);
		}else{
			if (c[i]<0) Add(m+1,c[i]); 
			else Add(l,c[i]);
		}
	}
	ll ans=Ans(m+1);
	if (ans>1e16) puts("NO");
	else puts("YES"),wwrite(ans);
}