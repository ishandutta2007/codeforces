#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100005
using namespace std;

int n,m,i,j,k,fa[maxn];

int f(int n){n++;return (n^(n&-n))>0;}
int g(int n){return (n==1)?0:(n-3)/2;}
void cover(int x,int p,int n){
	fa[x]=p;
	if (n==1) return;
	for(int k=1;k<=n;k=k<<1|1) if ((k<<1|1)>(n-1)/2){
		cover(x+1,x,k);
		cover(x+k+1,x,n-1-k);
		return;
	}
}

void write(){
	printf("YES\n");
	for(i=1;i<=n;i++) printf("%d ",fa[i]);	
}

void cover(int st,int m){
	for(int i=2;i<=m;i++) fa[st+i-1]=st+i/2-1;
}

int main(){
	scanf("%d%d",&n,&m);
	if (!(n&1)) printf("NO\n"),exit(0);
	if (m<f(n)||m>g(n)) printf("NO\n"),exit(0);
	if (n==9&&m==2) printf("NO\n"),exit(0);
	if (n==1) printf("YES\n0\n"),exit(0);
	if (m<=1) {
		if (f(n)==m) 
			cover(1,n),write();
		else printf("NO\n");
		exit(0);
	} 
	for(i=0;i<(m-1);i++) fa[2*i+2]=fa[2*i+3]=2*i+1;
	cover(2*m-1,n-2*(m-1));
	if (!f(n-2*(m-1))) fa[n]=fa[n-1]=2;
	write();
}