#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1e6+7;
int n,m,p[N],sb[N],sc[N];
char s[N];
inline void work(){
	n=read(),scanf("%s",s+1),m=0;
	for(int i=1;i<=n;i++){
		sb[i]=sb[i-1]+(s[i]=='b');
		sc[i]=sc[i-1]+(s[i]=='c');
		if(s[i]=='a')p[++m]=i;
	}
	int ans=1e9+1;
	for(int i=1;i<m;i++){
		for(int j=i+1;j<=m && j<=i+2;j++)
			if(j-i+1>max(sb[p[j]]-sb[p[i]],sc[p[j]]-sc[p[i]]))ans=min(ans,p[j]-p[i]+1);
//		int pos=
	}
	if(ans>1e9)ans=-1;
	printf("%d\n",ans);
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int test=read();
	while(test--)work();
    return 0;
}