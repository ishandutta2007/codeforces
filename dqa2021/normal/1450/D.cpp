#include<cstdio>
#include<algorithm>
#include<cctype>
#include<cmath>
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

int n,w[300010];
int c[300010];
bool ans[300010];
void solve(){
	n=read();
	for (int i=1;i<=n;i++) c[i]=0;
	for (int i=1;i<=n;i++) w[i]=read(),c[w[i]]++;
	int l=0,r=n+1;
	for (int i=1;i<n;i++){
		if (!c[i]){
			for (;i<n;i++) ans[i]=0;
			break;
		}
		ans[i]=1;
		if (c[i]!=1){
			for (i++;i<n;i++) ans[i]=0;
			break;
		}
		if (w[l+1]==i) l++;
		else if (w[r-1]==i) r--;
		else{
			for (i++;i<n;i++) ans[i]=0;
			break;
		}
	}
	ans[n]=1;
	for (int i=1;i<=n;i++) if (!c[i]) ans[n]=0;
	for (int i=n;i;i--) putchar(ans[i]?'1':'0');
	puts("");
}
int main()
{
	for (int T=read();T--;) solve();
}