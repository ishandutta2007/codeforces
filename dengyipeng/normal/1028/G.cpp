#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#define ll long long
#define maxn 10005
using namespace std;

ll g[6];
ll F(ll x,int c){
	if (x>=10000) return x+g[c]-1;
	if (c==1) return x+min(x,10000ll);
	ll v=min(x,10000ll)+1; x--;
	for(int i=1;i<=v;i++)
		x=F(x+1,c-1);
	return x;
}

ll d[maxn];
void doit(ll x,int c){
	ll v=min(x,10000ll)+1,s=x; x--;
	if (c==1){
		for(int i=1;i<=v;i++) x++,d[i]=x;
	} else {
		for(int i=1;i<=v;i++)
			x=F(x+1,c-1),d[i]=x;
	}
	printf("%lld ",v-1);
	for(int i=1;i<=v-1;i++) printf("%lld ",d[i]);
	printf("\n"),fflush(stdout);
	int k; scanf("%d",&k);
	if (k==-1) exit(0);
	if (k==0) doit(s,c-1); else 
		doit(d[k]+1,c-1);
}

int main(){
	g[1]=10001;for(int i=2;i<=4;i++)g[i]=g[i-1]*10001;
	doit(1,5);
}