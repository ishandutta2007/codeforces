#include<bits/stdc++.h>
#define ll long long
using namespace std;
typedef pair<int,int> pii;
int read(){
	int x=0,b=1;char c;do c=getchar();while((c>'9'||c<'0')&&c!='-');
	if(c=='-')b=0;do x=x*10+c-'0',c=getchar();while(c>='0'&&c<='9');return b?x:-x;
}
const int maxn=1000010;
int i,j,k,n,m,T,a[maxn][2],s[maxn][2];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		s[n+1][1]=0;s[n+1][0]=0;
		for(i=1;i<=n;i++)a[i][0]=read();
		for(i=1;i<=n;i++)a[i][1]=read();
		for(i=1;i<=n;i++)s[i][1]=s[i-1][1]+a[i][1];
		for(i=n;i>=1;i--)s[i][0]=s[i+1][0]+a[i][0];
		int ans=2000000000;
		for(i=1;i<=n;i++)ans=min(ans,max(s[i+1][0],s[i-1][1]));
		printf("%d\n",ans);
	}
}