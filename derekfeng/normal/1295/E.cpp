#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
int n,p[200004],a[200004],n_=1;
ll ans,dat[530000],cnt[530000];
map<int,int>mp;
void upd(int l,int r,int id,int a,int b,ll x){
	if (r<a || b<l) return;
	if (a<=l && r<=b){
		dat[id]+=x;
		cnt[id]+=x;
		return;
	}
	upd(l,(l+r)/2,id*2+1,a,b,x),upd((l+r)/2+1,r,id*2+2,a,b,x);
	dat[id]=min(dat[id*2+1],dat[id*2+2])+cnt[id];
}
int main(){
	read(n);while (n_<n) n_<<=1;
	for (int i=0;i<n;i++) read(p[i]),mp[p[i]]=i;
	for (int i=0;i<n;i++) read(a[i]);
	for (int i=0;i<530000;i++) dat[i]=1e16;
	ll now=0;
	for (int i=0;i<n-1;i++){
		now+=a[i];
		upd(0,n_-1,0,i,i,now-(10000000000000000));
	}
	ans=a[0];
	for (int i=1;i<=n;i++){
		if (mp[i]!=n-1)upd(0,n_-1,0,mp[i],n-2,-a[mp[i]]);
		if (mp[i]!=0) upd(0,n_-1,0,0,mp[i]-1,a[mp[i]]);
		ans=min(ans,dat[0]);
	}
	cout<<ans;
}