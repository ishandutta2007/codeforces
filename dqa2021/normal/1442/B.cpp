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
typedef long long ll;
const int mod=998244353;

int n,m,a[200010],b[200010],ia[200010];
int t[200010];
void init(){
	
}
int solve(){
	n=read(),m=read();
	for (int i=1;i<=n;i++) ia[a[i]=read()]=i,t[i]=0;
	for (int i=1;i<=m;i++) b[i]=read(),t[ia[b[i]]]=i;
	int ans=1;
	for (int i=1;i<=n;i++){
		if (!t[i]) continue;
		int s=0;
		if (i>1) s+=t[i-1]<t[i];
		if (i<n) s+=t[i+1]<t[i];
		ans=ans*s%mod; 
	}
	return ans;
}
int main()
{
	for (int T=read();T--;) init(),printf("%d\n",solve());
}