#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pc putchar
#define chkmx(a,b) (a)=max((a),(b))
#define chkmn(a,b) (a)=min((a),(b))
#define fi first
#define se second
using namespace std;
template<class T>
void read(T&x){x=0;char c=getchar();bool f=0;for(;!isdigit(c);c=getchar())f^=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<class T,class ...ARK>void read(T&x,ARK&...ark){read(x);read(ark...);}
template<class T>void write(T x){if(x<0)pc('-'),x=-x;if(x>=10)write(x/10);pc(x%10+'0');}
const int N=5010;
int t,n,fa[N],dep[N],d,cnt,a[N];bool vis[N];
signed main(){
	read(t);
	while(t--){
		read(n,d);int mx=0;
		for(int i=1;i<=n;i++)vis[i]=0;
		for(int i=2;i<=n;i++)
			fa[i]=i/2,dep[i]=dep[fa[i]]+1,d-=dep[i];
		if(d<0){puts("NO");continue;}
		mx=dep[n];
		int x=n;while(x)vis[x]=1,a[dep[x]]=x,x=fa[x];
		for(int i=n;i;i--){
			if(vis[i])continue;
			while(d){
				fa[i]=a[dep[fa[i]]+1];dep[i]=dep[fa[i]]+1;d--;
				if(dep[i]>mx){mx++,a[mx]=i;break;}
			}
		}
		if(d){puts("NO");continue;}
		puts("YES");
		for(int i=2;i<=n;i++)printf("%d ",fa[i]);puts("");
	}
}