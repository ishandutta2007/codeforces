#include<cstdio>
#include<algorithm>
#include<cctype>
#include<vector>
#define pb push_back
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

int n;
vector<int> e[300010];
int ans[300010];
void init(){
	for (int i=1;i<=n;i++) vector<int>().swap(e[i]);
}
void solve(){
	n=read();
	for (int i=1;i<=n;i++) e[i].pb(0);
	for (int i=1;i<=n;i++){
		int x=read();
		e[x].pb(i);
	}
	for (int i=1;i<=n;i++) e[i].pb(n+1),ans[i]=1e9;
	for (int i=1;i<=n;i++){
		int t=0;
		for (int j=0;j+1<e[i].size();j++){
			t=max(t,e[i][j+1]-e[i][j]);
		}
		ans[t]=min(ans[t],i);
	}
	for (int i=2;i<=n;i++) ans[i]=min(ans[i],ans[i-1]);
	for (int i=1;i<=n;i++) printf("%d ",ans[i]==1e9?-1:ans[i]);
	puts("");
}
int main()
{
	for (int T=read();T--;) init(),solve();
	return 0;
}