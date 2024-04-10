#include<cstdio>
#include<set>
using namespace std;
const int o=1e5+10;
int T,n,m,fa[o],st[o],tp;char s[o];bool z[o],flg;set<int> S;
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
inline void slv(){
	scanf("%s%d",s+1,&m);
	for(int i=1;i<=n;++i) fa[i]=i;
	for(int i='a';i<='z';++i) z[i]=0;
	for(char c;m--;z[c]=1) for(c=getchar();c<'a'||c>'z';c=getchar());
	int res=0;
	for(int i=1;i<=n;++i) if(z[s[i]]) S.insert(i);
	for(;!S.empty();++res){
		tp=flg=0;
		for(set<int>::iterator iter=S.begin();iter!=S.end();++iter) st[++tp]=*iter;
		for(int i=1,j;i<=tp;++i) if(!(j=fr(st[i]-1))) S.erase(st[i]);else S.erase(j),fa[j]=j-1,flg=1;
		if(!flg) break;
	}
	printf("%d\n",res);
}
int main(){
	for(scanf("%d",&T);T--;slv(),S.clear()) scanf("%d",&n);
	return 0;
}