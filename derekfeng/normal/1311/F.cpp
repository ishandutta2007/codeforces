#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
void read(int &x){
	register char ch=getchar();x=0;int ret=1;
	for(;ch=='\n'||ch==' ';ch=getchar());
	if(ch=='-')ret=-1,ch=getchar();
	for(;ch>='0'&&ch<='9';x=x*10+ch-'0',ch=getchar());
	x*=ret;
}
void write(ll x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
pii a[200004];
int n,dat[200004],cnt;
ll d[200004];
void upd(int id,int x){
	while (id<=cnt){
		dat[id]++,d[id]+=x;
		id+=(id&-id);
	}
}
pair<int,ll> ans(int id){
	int res=0;
	ll res_=0;
	while (id){
		res+=dat[id],res_+=d[id];
		id-=(id&-id);
	}
	return make_pair(res,res_);
}
map<int,int>mp;
ll ret;
int main(){
	read(n);
	for(int i=1;i<=n;i++)read(a[i].fi);
	for(int i=1;i<=n;i++)read(a[i].se),mp[a[i].se]=1;
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)it->second=++cnt;
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		a[i].se=mp[a[i].se];
		pair<int,ll> P=ans(a[i].se);
		ret+=1ll*P.fi*a[i].fi-P.se;
		upd(a[i].se,a[i].fi);
	}
	write(ret);
}