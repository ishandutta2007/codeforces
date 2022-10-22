#include<bits/stdc++.h>
using namespace std;

#define reg register
typedef long long ll;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

char IO;
int rd(){
	int s=0,f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=4e7,P=1e9+7;

bool be;
int n,a,b;
int dp1[N],dp2[N];
int ch1[]={0,1,2,5,10,20,50,100};
int ch2[]={0,5,10,20,50,100,200};
int pre[N];
bool ed;


int main(){
	//cout<<&ed-&be<<endl;
	n=rd(),a=rd(),b=rd();
	dp1[0]=dp2[0]=1;
	rep(i,1,7) rep(j,ch1[i],n/a+1) dp1[j]|=dp1[j-ch1[i]];
	rep(i,1,6) rep(j,ch2[i],n/b+1) dp2[j]|=dp2[j-ch2[i]];
	int ans=n;
	rep(j,1,n/b+1) if(dp2[j]) pre[j]=j;
	else pre[j]=pre[j-1];
	rep(i,0,n/a) if(dp1[i]) {
		int t=n-i*a;
		int r=t-b*pre[t/b];
		ans=min(ans,r);
	}
	printf("%d\n",ans);
}