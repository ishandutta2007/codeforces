#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int M=1e5+5;
inline int read(){
	char c=getchar();int x=0,f=1;
	for(;c<'0'||c>'9';c=getchar())if(c=='-')f=0;
	for(;c<='9'&&c>='0';c=getchar())x=(x<<1)+(x<<3)+(c^48);
	return f?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
int a[M],b[M];
int main(){
	int T=read();
	while(T--){
		int n=read(),sum1=0,sum2=0,cnt=0,no1=n/4,no2=n/4,la=4-n%4;
		bool fl1=0;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		for(int i=1;i<=n;i++)a[i]=read(),sum1+=a[i];
		for(int i=1;i<=n;i++)b[i]=read(),sum2+=b[i];
		sort(a+1,a+1+n);sort(b+1,b+1+n);
		for(int i=1;i<=no1;i++)sum1-=a[i],sum2-=b[i];
		if(sum1>=sum2){
			printf("0\n");continue;
		}
		while(sum1<sum2){
			sum1+=100;cnt++;
			if((n+cnt)%4==0)sum1-=a[++no1];
			else if(no2!=0)sum2+=b[no2--];
//			printf("%d %d %d\n",cnt,sum1,sum2);
			if(sum1>=sum2)break;
		}
		printf("%d\n",cnt);continue;
	}
	return 0;
}