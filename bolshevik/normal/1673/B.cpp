#include<cstdio>
#include<cstring>
using namespace std;
const int o=2e5+10;
int T,n,lst[o];char s[o];bool vis[o];
inline void slv(){
	for(int i=0;i<26;++i) lst[i]=vis[i]=0;
	for(int i=1;i<=n;++i) vis[s[i]-=97]=1;
	for(int i=1;i<=n;lst[s[i]]=i,++i) if(lst[s[i]])
		for(int j=0;j<26;++j) if(vis[j]&&lst[j]<lst[s[i]]){printf("NO\n");return;}
	printf("YES\n");
}
int main(){
	for(scanf("%d",&T);T--;slv()) scanf("%s",s+1),n=strlen(s+1);
	return 0;
}