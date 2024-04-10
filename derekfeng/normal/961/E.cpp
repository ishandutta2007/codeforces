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
int n,a[400004],w[400004],cnt;
map<int,int>mp;
ll ans;
struct BIT{
	int dat[400004];
	void init(){
		memset (dat,0,sizeof(dat));
	}
	void upd(int id,int add_){
		while (id<=4e5+2){
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
vector<int>W[200004];
int main(){
	read(n);
	Tree.init();
	for (int i=1;i<=n;i++) read(a[i]),mp[a[i]]=1,mp[i]=1;
	for (map<int,int>::iterator it=mp.begin();it!=mp.end();it++) it->second=++cnt;
	for (int i=1;i<=n;i++)W[min(i-1,a[i])].push_back(i);
	for (int i=1;i<=n;i++){
		Tree.upd(mp[a[i]],1);
		for (int j=0;j<W[i].size();j++)
			ans+=Tree.qry(mp[W[i][j]],4e5+2);
	}
	write(ans);
}