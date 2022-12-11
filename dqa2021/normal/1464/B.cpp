#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cstring>
#include<iostream> 
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
typedef long long ll;

char s[100010]; int n;
int pre[100010],suf[100010];
ll X,Y;
int c[100010],top;
ll ans=1e18;
ll A;
int main()
{
	scanf("%s",s+1);
	X=read(),Y=read();
	n=strlen(s+1);
	for (int i=1;i<=n;i++) pre[i]=pre[i-1]+(s[i]=='1');
	for (int i=n;i;i--) suf[i]=suf[i+1]+(s[i]=='1');
	for (int i=1;i<=n;i++){
		if (s[i]=='?') c[++top]=i;
	}
	for (int i=1;i<=n;i++){
		if (s[i]=='0'||s[i]=='?'){
			A+=suf[i];
		}
	}
	ans=A*X+(1LL*pre[n]*(n-pre[n])-A)*Y;
	int tot=pre[n];
	for (int i=top;i;i--){
		tot++;
		int x=c[i];
		A-=suf[x]+top-i;
		A+=x-1-pre[x];
		ans=min(ans,A*X+(1LL*(tot)*(n-tot)-A)*Y);
	}
	for (int i=top;i;i--){
		tot--;
		int x=c[i];
		A+=suf[x];
		A-=x-1-pre[x]-i+1;
		ans=min(ans,A*X+(1LL*(tot)*(n-tot)-A)*Y);
	}
	cout<<ans<<endl;
}