#include<cstdio>
#include<algorithm>
#define ll long long
#define maxn 4000000
using namespace std;
const int ha=1<<30;
int a,b,c,miu[maxn+5];
int zs[maxn/5],t=0,D,low[maxn+5];
int d[maxn+5],to[maxn+5],ans=0;
bool v[maxn+5];

inline void init(){
	for(int i=1;i<=a;i++)
	    for(int j=1;j<=b;j++) to[i*j]++;
	miu[1]=d[1]=low[1]=1;
	
	for(int i=2;i<=maxn;i++){
		if(!v[i]) zs[++t]=i,miu[i]=-1,low[i]=i,d[i]=2;
		for(int j=1,u;j<=t&&(u=zs[j]*i)<=maxn;j++){
			v[u]=1;
			
			if(!(i%zs[j])){
				low[u]=low[i]*zs[j];
				if(low[i]==i) d[u]=d[i]+1;
				else d[u]=d[low[u]]*d[i/low[i]];
				break;
			}
			low[u]=zs[j],d[u]=d[i]<<1,miu[u]=-miu[i];
		}
	}
    
	for(int i=1;i<=maxn;i++) d[i]+=d[i-1];
}

inline int add(int x,int y){
	x+=y;
	return x>=ha?x-ha:x;
}

inline void calc(){
	for(int i=1,sum;i<=c;i++) if(miu[i]){
		sum=0;
		for(int j=i;j<=D;j+=i) sum=add(sum,to[j]*(ll)(d[j/i]-d[j/i-1])%ha);
		sum=sum*(ll)d[c/i]%ha;
		if(miu[i]==1) ans=add(ans,sum);
		else ans=add(ans,ha-sum);
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d%d%d",&a,&b,&c);
	if(a>b) swap(a,b);
	if(a>c) swap(a,c);
	if(b>c) swap(b,c);
	D=a*b;
	
	init();
	calc();
	
	return 0;
}