#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1000005
#define ll long long 
using namespace std;

int x,y,n,m,i,j,k,s[maxn],c[2],sc[2],all;
ll pre[maxn];
ll S(int a,int b){return (a^b)*(b*x+a*y);}

int main(){
	char ch=getchar();
	while (ch=='0'||ch=='1'||ch=='?') s[++n]=(ch=='?')?(-1):ch-'0',ch=getchar();
	scanf("%d%d",&x,&y);
	if (x<y) {
		swap(x,y);
		for(i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
//		for(i=1;i<=n;i++) if (s[i]>=0) s[i]^=1;
	}
	for(i=1;i<=n;i++) if (s[i]>=0) sc[s[i]]++; else all++;
	for(i=1;i<=n;i++) for(j=0;j<2;j++) if (s[i]<0&&j==1||j==s[i]){
		pre[i]=pre[i-1];
		if (s[i]<0)	for(k=0;k<2;k++) pre[i]+=S(k,j)*c[k];
		if (s[i]>=0) c[s[i]]++;
		for(k=0;k<2;k++) pre[i]+=S(j,k)*(sc[k]-c[k]);
	}
	c[0]=c[1]=0; ll sum=0,ans=pre[n]; int cnt=0;
	for(i=n;i>=1;i--) for(j=0;j<2;j++) if (s[i]<0&&j==0||j==s[i]){
		for(k=0;k<2;k++) sum+=S(j,k)*c[k];
		if (s[i]<0) for(k=0;k<2;k++) sum+=S(k,j)*(sc[k]-c[k]);
		if (s[i]<0) cnt++; else c[s[i]]++;
		ans=min(ans,sum+pre[i-1]+S(1,0)*(all-cnt)*cnt);
	}
	printf("%lld\n",ans);
}