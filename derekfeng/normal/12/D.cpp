#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define mkp make_pair
#define fi first
#define se second 
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(int x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
piii a[500005];
int n,cnt,ans;
map<int,int>mp; 
bool cmp(piii A,piii B){
	return A.fi.fi>B.fi.fi;
}
int d[500005];
vector<pii>v;
int qry(int id){int ret=0;while(id<=n)ret=max(ret,d[id]),id+=(id&-id);return ret;}
void add(int id,int x){while (id)d[id]=max(d[id],x),id-=(id&-id);}
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i].fi.fi);
	for (int i=1;i<=n;i++) read(a[i].fi.se),mp[a[i].fi.se]=1;
	for (int i=1;i<=n;i++) read(a[i].se); 
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt;
	sort (a+1,a+1+n,cmp);
	for (int i=1;i<=n;i++){
		if (i>1 && a[i].fi.fi<a[i-1].fi.fi){
			for (int j=0;j<v.size();j++) add(v[j].fi,v[j].se);
			v.clear(); 
		}
		int val=mp[a[i].fi.se];
		if (qry(val)>a[i].se) ans++;
		v.push_back(mkp(val-1,a[i].se));
	}
	write(ans);
}