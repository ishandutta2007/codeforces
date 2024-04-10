#include<bits/stdc++.h>
#define Tp template<typename Ty>
#define Ts template<typename Ty,typename... Ar>
#define Rg register
#define RI Rg int
#define Cn const
#define CI Cn int&
#define I inline
#define W while
#define N 1000
using namespace std;
int n,k,id[N+5],bl[N+5],ct,w[N+5][N+5];
namespace FastIO
{
	#define FS 100000
	#define pc(c) (FC==FE&&(clear(),0),*FC++=c)
	int OT;char FO[FS],OS[FS],*FC=FO,*FE=FO+FS;
	I void clear() {fwrite(FO,1,FC-FO,stdout),FC=FO;}
	Tp I void write(Ty x) {W(OS[++OT]=x%10+48,x/=10);W(OT) pc(OS[OT--]);pc(' ');}
}using namespace FastIO;
I void Col()
{
	RI i,j;for(++ct,i=1;i<=n;++i) bl[i]=(id[i]-1)/k+1;
	for(i=1;i<=n;++i) for(j=i+1;j<=n;++j) id[i]^id[j]&&bl[i]==bl[j]&&(w[i][j]=ct);
	if(bl[n]==1) return;for(i=1;i<=n;++i) id[i]=bl[i];Col();
}
int main()
{
	RI i,j;for(scanf("%d%d",&n,&k),i=1;i<=n;++i) id[i]=i;Col();
	for(printf("%d\n",ct),i=1;i<=n;++i) for(j=i+1;j<=n;++j) write(w[i][j]);return clear(),0;
}