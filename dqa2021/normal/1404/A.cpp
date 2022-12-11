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

char s[300010];
int sum[300010];
void init(){
	
}
void solve(){
	int n=read(),k=read();
	scanf("%s",s+1);
	int A=0,B=0,C=0;
	for (int i=1;i<=k;i++){
		int t=-1;
		for (int j=i;j<=n;j+=k){
			if (s[j]=='?') continue;
			if (s[j]=='0'&&t==1) return puts("NO"),void();
			if (s[j]=='1'&&t==0) return puts("NO"),void();
			t=s[j]&1;
		}
		if (t==-1) A++;
		else if (!t) B++;
		else C++;
	}
	if (B>(k>>1)||C>(k>>1)) return puts("NO"),void();
	 return puts("YES"),void();
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
 }