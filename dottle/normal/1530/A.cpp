#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=0;
	for(;c<='9'&&c>='0';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return f?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
char s[1005];
int main(){
	int T=read();
	while(T--){
		scanf("%s",s+1);int n=strlen(s+1),ans=0;;
		for(int i=1;i<=n;i++)ans=max(ans,s[i]^48);
		printf("%d\n",ans);
	}
	return 0;
}