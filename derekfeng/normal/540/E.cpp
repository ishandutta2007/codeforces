#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void read(int &x){
	char ch=getchar();x=0;
	for (;ch==' '||ch=='\n';ch=getchar());
	for (;ch!=' '&&ch!='\n';x=x*10+ch-'0',ch=getchar());
}
void write(ll x){
	if (x>9) write(x/10);
	putchar(x%10+'0');
}
struct BIT{
	int dat[200004];
	void init(){
		memset (dat,0,sizeof(dat));
	}
	void upd(int id,int add_){
		while (id<=2e5){
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
}Tree;
ll ans;
int n,cnt,a[100004],b[200004],num[200004],f[200004];
map<int,int>mp;
int main(){
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),read(b[i]),mp[a[i]]=mp[b[i]]=1;
	for (int i=1;i<=2e5;i++) f[i]=i;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) num[++cnt]=it->first,it->second=cnt;
	for (int i=1;i<=n;i++) swap(f[mp[a[i]]],f[mp[b[i]]]);
	for (int i=1;i<=cnt;i++){
		if (i<f[i]) ans+=num[f[i]]-num[i]-f[i]+i;
		if (i>f[i]) ans+=num[i]-num[f[i]]+f[i]-i;
	}
	Tree.init();
	for (int i=cnt;i>0;i--){
		ans+=Tree.ANS(f[i]); 
		Tree.upd(f[i],1);
	}
	write(ans);
}