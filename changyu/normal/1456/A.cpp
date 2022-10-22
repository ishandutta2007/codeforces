#include<cstdio>
#include<algorithm>
const int N=1e5+3;
int n,p,k,x,y,b[N],ans;char a[N];
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d%d%s%d%d",&n,&p,&k,a+1,&x,&y);
	for(int i=n;i;i--)b[i]=(i+k<=n?b[i+k]:0)+(a[i]=='0');
	ans=0x3f3f3f3f;
	for(int i=0;i<=n-p;i++)
	  ans=std::min(ans,i*y+b[i+p]*x);
	printf("%d\n",ans);
	}return 0;
}