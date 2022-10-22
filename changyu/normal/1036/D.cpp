#include<cstdio>
#include<algorithm>
inline int read(){
	int a=0;char c=getchar();
	for(;c<48||c>57;c=getchar());for(;c>47&&c<58;a=a*10+c-48,c=getchar());
	return a;
}
typedef long long ll;
const int N=3e5+10;
int n,m,s;ll a[N],b[N];
int main(){
	n=read();for(int i=1;i<=n;i++)a[i]=read()+a[i-1];
	m=read();for(int i=1;i<=m;i++)b[i]=read()+b[i-1];
	if(a[n]!=b[m])return 0*puts("-1");
	for(int i=1;i<=n;i++)
	  s+=b[std::lower_bound(b+1,b+1+m,a[i])-b]==a[i];
	printf("%d",s);
	return 0;
}