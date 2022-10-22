#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define chkmx(a,b) ((a)=max((a),(b)))
#define chkmn(a,b) ((a)=min((a),(b)))
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
//#define int long long
typedef long long ll;
#define fi first
#define se second
#define lc (x<<1)
#define rc (x<<1|1)
#define mid (l+r>>1)
const int N=3e5+100,M=20;
int n,fath[N][M];
int a[N],c[N];
int get(int v){
	for(int j=M-1;~j;j--)
		if(a[fath[v][j]])
			v=fath[v][j];
	return v;
}
signed main(){
	read(n,a[1],c[1]);
	for(int i=2;i<=1+n;i++){
		int op,p,v,w;read(op);
		if(op==1){
			read(p,a[i],c[i]);p++;
			fath[i][0]=p;
			for(int j=1;j<M;j++)fath[i][j]=fath[fath[i][j-1]][j-1];
		}else{
			read(v,w);v++;ll _=w,ans=0;
			while(a[v]&&w){
				int x=get(v);
				if(w>a[x]){
					w-=a[x],ans+=1ll*a[x]*c[x];
					a[x]=0;
				}else{
					a[x]-=w,ans+=1ll*w*c[x];
					w=0;
				}
			}
			write(_-w);putchar(' ');
			write(ans);putchar('\n');
			fflush(stdout);
		}
	}
}