// 
//	When Panole says a theory is obvious,  
//		You can solve it in a year if you are a genius.
//
#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ref(i,x,y)for(int i=x;i<=y;++i)
#define def(i,x,y)for(int i=x;i>=y;--i)
#define eef(i,x)for(int i=head[x],y=e[i].to;i;i=e[i].next,y=e[i].to)
int read(){char c=getchar();int d=0,f=1;for(;c<'0'||c>'9';c=getchar())if(c=='-')f=-1;for(;c>='0'&&c<='9';d=d*10+c-48,c=getchar());return d*f;}
char Read(){char c=getchar();while(c<'0'||c>'9')c=getchar();return c;}
void print(int s){if(!s){putchar('0');return;}if(s<0)putchar('-'),s=-s;int t[20],n=0;while(s)t[++n]=s%10,s/=10;def(i,n,1)putchar(t[i]+'0');}
int getdigit(char c){return (c<'0'||c>'9')?-1e9:(c-'0');}
typedef pair<int,int>PII;
typedef long long LL;
const int N=110;
int n,m; int h[N],qs[N],s[N],fL[N][N],fR[N][N];
int mk[N],ansR[N],ansL[N],id[N];
bool solveR(int x,int y){
	ref(i,0,N-1)mk[i]=0;
	mk[y+1]=-1;
	int op=0;
	def(i,y,x)if(h[i]) {
		ref(j,i+1,y+1)if(mk[j]&&h[i]+fR[i][j-1]>=0)
			{ mk[i]=j; break; }
		op=i;
	}
	ansR[0]=0;
	if(!op)return 1;
	if(!mk[op])return 0;
	for(;op!=y+1;op=mk[op])ansR[++ansR[0]]=op;
	ref(i,0,N-1)mk[i]=0;
	ref(i,1,ansR[0])mk[ansR[i]]=1;
	ref(i,1,ansR[0]/2)swap(ansR[i],ansR[ansR[0]+1-i]);
	ref(i,x,y)if(h[i]&&!mk[i])ansR[++ansR[0]]=i;
	return 1;
}
bool solveL(int x,int y){
	ref(i,0,N-1)mk[i]=0;
	mk[x-1]=-1;
	int op=0;
	ref(i,x,y)if(h[i]) {
		ref(j,x-1,i-1)if(mk[j]&&h[i]+fL[i][j+1]>=0)
			{ mk[i]=j; break; }
		op=i;
	}
	ansL[0]=0;
	if(!op)return 1;
	if(!mk[op])return 0;
	for(;op!=x-1;op=mk[op])ansL[++ansL[0]]=op;
	ref(i,0,N-1)mk[i]=0;
	ref(i,1,ansL[0])mk[ansL[i]]=1;
	ref(i,1,ansL[0]/2)swap(ansL[i],ansL[ansL[0]+1-i]);
	ref(i,x,y)if(h[i]&&!mk[i])ansL[++ansL[0]]=i;
	return 1;
}
int main(){
	n=read();m=read();
	ref(i,1,m){ int p=read();h[p]=read();id[p]=i; }
	ref(i,1,n) s[i]=read(),qs[i]=qs[i-1]+s[i];
	ref(i,0,N-1)ref(j,0,N-1)fL[i][j]=fR[i][j]=1e9;
	ref(i,1,n) ref(j,i,n)fR[i][j]=min(fR[i][j-1],qs[j]-qs[i-1]);
	ref(i,1,n) def(j,i,1)fL[i][j]=min(fL[i][j+1],qs[i]-qs[j-1]);
	ref(i,1,n){
		if(solveR(1,i)&&solveL(i+1,n)){
			if(!ansR[0])printf("%d\n",i+1);
			else printf("%d\n",i);
			ref(i,1,ansR[0])printf("%d ",id[ansR[i]]);
			ref(i,1,ansL[0])printf("%d ",id[ansL[i]]);
			printf("\n");
			return 0;
		}
	}
	printf("-1\n");
}