#include<cstdio>
#include<cstring>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}while(c<='9'&&c>='0') a=a*10+c-48,c=getchar();a*=f;}
const int o=1e5+10;
int T,n,vis[30],t,x,y;char s[o];
int main(){
	for(read(T);T--;putchar('\n')){
		scanf("%s",s+1);n=strlen(s+1);x=y=0;
		for(int i=0;i<27;++i) vis[i]=0;
		for(int i=1;i<=n;++i) ++vis[s[i]-96];
		for(int i=1;i<27;++i) if(vis[i]==1){
			putchar(i+96);--vis[i];vis[0]=1;
			for(int j=1;j<27;++j) while(vis[j]--) putchar(j+96);
			break;
		}
		else if(vis[i]==n){vis[0]=1;while(n--) putchar(i+96);}
		if(vis[0]) continue;
		for(int i=1;i<27;++i) if(vis[i]){t=i;break;}
		if(vis[t]<=n/2+1){
			putchar(t+96);putchar(t+96);--vis[t];
			for(int i=t+1;--vis[t];putchar(t+96)){for(;!vis[i];++i);--vis[i];putchar(i+96);}
			for(int i=1;i<27;++i) while(vis[i]--) putchar(i+96);
			continue;
		}
		for(int i=t+1;i<27;++i) if(vis[i]) if(!x) x=i;else if(!y) y=i;
		if(!y){
			putchar(t+96);
			while(vis[x]--) putchar(x+96);
			while(--vis[t]) putchar(t+96);
			continue;
		}
		putchar(t+96);putchar(x+96);
		while(--vis[t]) putchar(t+96);
		putchar(y+96);--vis[y];
		while(--vis[x]) putchar(x+96);
		for(int i=1;i<27;++i) while(vis[i]--) putchar(i+96);
	}
	return 0;
}