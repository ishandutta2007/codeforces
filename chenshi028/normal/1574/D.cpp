#include<cstdio>
#include<vector>
#include<utility>
#include<map>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=1e5+10;
int n,c[o],m,t[o][20],g[20],opt[20],ans;vector<int> a[20];map<pair<int,int>,bool> ban;
inline pair<int,int> hsh(int s[]){
	int res1=0,res2=0;
	for(int i=1;i<=n;++i)
		res1=(res1*1ll*(c[i]+1)+s[i])%998244353,
		res2=(res2*1ll*(c[i]+1)+s[i])%1000000009;
	return make_pair(res1,res2);
}
inline void upd(){
	if(ban[hsh(g)]) return;
	int res=0;
	for(int i=1;i<=n;++i) res+=a[i][g[i]-1];
	if(res>ans){
		ans=res;
		for(int i=1;i<=n;++i) opt[i]=g[i];
	}
}
int main(){
	read(n);
	for(int i=1,j,k;i<=n;++i)
		for(read(c[i]),j=c[i];j;--j) read(k),a[i].push_back(k);
	read(m);
	for(int i=1;i<=m;ban[hsh(t[i++])]=1)
		for(int j=1;j<=n;++j) read(t[i][j]);
	for(int i=1;i<=n;++i) g[i]=c[i];upd();
	for(int i=1;i<=m;++i){
		for(int j=1;j<=n;++j) g[j]=t[i][j];
		for(int j=1;j<=n;++j)
			if(g[j]>1) --g[j],upd(),++g[j];
	}
	for(int i=1;i<=n;++i) printf("%d ",opt[i]);
	return 0;
}