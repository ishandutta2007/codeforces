#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=3e5+5;
inline int read(){
	char c=getchar();int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=0;
	for(;c<='9'&&c>='0';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return f?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
int a[M],b[M],c[M],ans[M];
bool vis[M],v2[M];
int main(){
	int T=read();
	while(T--){
		int n=read(),tm=1,cn=0,st=0;
		for(int i=1;i<=n;i++)b[i]=a[i]=read();
		sort(a+1,a+1+n);
		int k=unique(a+1,a+1+n)-a-1;
		printf("%d\n",k);
		for(int i=1;i<=k;i++)vis[a[i]]=1;
//		for(int i=1;i<=k;i++)printf("%d ",a[i]);puts("");
		for(int i=n;i>=1;i--)if(!vis[i])c[++cn]=i;
//		for(int i=1;i<=cn;i++)printf("%d ",c[i]);puts("");
//		for(int i=1;i<=n;i++)printf("%d ",b[i]);puts("");
		for(int i=1;i<=n;i++){
			if(!v2[b[i]])ans[i]=b[i],v2[b[i]]=1;
			else if(i!=b[i])ans[i]=c[tm++];
			else c[++cn]=c[tm++],ans[i]=c[tm++];
		}
		for(int i=1;i<=n;i++)
			if(ans[i]==i)
				for(int j=1;j<=n;j++)
					if(b[j]==b[i])
						swap(ans[i],ans[j]); 
		for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
		for(int i=0;i<=n;i++)
			a[i]=b[i]=c[i]=vis[i]=v2[i]=0;
	}
	return 0;
}