#include<cstdio>
void read(int&x)
{
	x=0;char c;
	do{c=getchar();}while(c<'0'||c>'9');
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
}
#define MAX 100000
int x[MAX+5],y[MAX+5],w[MAX+5],c[MAX+5];
int main()
{
	int n,m,k,i,ans=-1;
	read(n);read(m);read(k);
	for(i=0;i<m;i++){read(x[i]);read(y[i]);read(w[i]);}
	while(k--){read(i);c[i]=1;}
	for(i=0;i<m;i++)if(c[x[i]]^c[y[i]])if(ans<0||w[i]<ans)ans=w[i];
	printf("%d",ans);
}