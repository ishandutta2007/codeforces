#include<cstdio>
#include<algorithm>
#include<cctype>
using namespace std;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
     
    int n,a[110];
    int p[110],q[110];
    void get(int &x,int &y){
    	int s=read(),t=read();
    	x=s-p[n+1],y=t-q[n+1]; p[n+1]=s; q[n+1]=t;
    }
    int main()
    {
    	scanf("%d",&n); scanf("%d%d",p+n+1,q+n+1);
    	for (int i=n-1;i>3;i--) printf("+ %d\n",i),fflush(stdout),get(p[i],q[i]);
    	printf("+ 3\n"); fflush(stdout); get(p[3],q[3]);
    	printf("+ 1\n"); fflush(stdout); get(p[2],q[2]);
    	printf("+ 2\n"); fflush(stdout); get(p[1],q[1]);
    	printf("+ 1\n"); fflush(stdout); get(p[0],q[0]);
    	if (p[0]==0&&p[2]==0) a[1]=0;
    	else{
    		int s=0; a[1]=1;
    		while (s<p[2]) s+=a[1],a[1]++;
    	}
    	a[3]=q[0]-q[2]-1; a[2]=q[2]/(a[3]+1);
    	a[4]=(q[1]-(a[3]+1)*(a[1]+1))/(a[3]+1)-1;
    	for (int i=5;i<=n;i++){
    		a[i]=(q[i-2]-a[i-4]*a[i-3]-a[i-3]*(a[i-1]+1))/(a[i-1]+1)-1;
    	}
    	a[n]++;
    	printf("!"); for (int i=1;i<=n;i++) printf(" %d",a[i]); puts(""); fflush(stdout);
    	return 0;
    }