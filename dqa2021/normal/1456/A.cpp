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

int n,p,k;
char s[100010];
int x,y;
int ans;
int dp[100010];
void init(){
//	...
}
void solve(){
	n=read(),p=read(),k=read();
	scanf("%s",s+1);
	x=read(),y=read();
	ans=2e9;
	for (int i=n;i;i--){
		if (s[i]=='0') dp[i]=1;
		else dp[i]=0;
		if (i+k<=n) dp[i]+=dp[i+k];
	}
	for (int i=p;i<=n;i++) ans=min(ans,(i-p)*y+dp[i]*x);
	printf("%d\n",ans);
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}