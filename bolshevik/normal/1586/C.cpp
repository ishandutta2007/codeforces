#include<cstdio>
using namespace std;
const int o=1e6+10;
int n,m,q,l,r,z[o];char s[o];
inline int hsh(int x,int y){return (x-1)*m+y;}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) scanf("%s",s+(i-1)*m+1);
	for(int i=1;i<=m;++i) z[i]=o;
	for(int i=2;i<=n;++i) for(int j=1;j<m;++j)
		if(s[hsh(i,j)]=='X'&&s[hsh(i-1,j+1)]=='X') z[j]=j+1;
	for(int i=m;--i;) if(z[i]==o) z[i]=z[i+1];
	for(scanf("%d",&q);q--;printf(r>=z[l]?"NO\n":"YES\n")) scanf("%d%d",&l,&r);
	return 0;
}