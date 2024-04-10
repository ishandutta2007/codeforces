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
void readi(ll &x){
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
int cnt;
struct BIT{
	int dat[200004];
	void init(){
		memset (dat,0,sizeof(dat));
	}
	void upd(int id,int add_){
		while (id<=cnt){
			dat[id]+=add_;
			id+=(id&-id);
		}
	}
	int ANS(int id){
		int ret=0;
		while (id){
			ret+=dat[id];
			id-=(id&-id);
		}
		return ret;
	}
	int qry(int l,int r){
		return ANS(r)-ANS(l-1);
	}
}Tree;
int n,w[200004];
ll d[200004],ans,num[200004],t;
map<ll,int>mp;
int main(){
	read(n),readi(t);
	Tree.init();
	mp[0]=1;
	for (int i=1;i<=n;i++){
		int x;read(x);d[i]=d[i-1]+x,mp[d[i]]=1;
	}
	for (map<ll,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt,num[cnt]=it->first;
	for (int i=1;i<=n;i++) w[i]=mp[d[i]];
	Tree.upd(mp[0],1);
	for (int i=1;i<=n;i++){
		int got=upper_bound(num+1,num+1+cnt,d[i]-t)-num;
		ans+=Tree.qry(got,cnt);
		Tree.upd(w[i],1);
	}
	write(ans);
}