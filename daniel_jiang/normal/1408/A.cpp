// wish to get better qwq
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105;
int t,n,a[N],b[N],c[N],p[N],vst[N][5];
bool ok;
template <typename T> void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
void wr(int x){
	if(x<0) x=-x,putchar('-');
	if(x<10) putchar(x+'0');
	if(x>9) wr(x/10),putchar(x%10+'0');
}
void dfs(int x,int qaq){
	if(ok) return ;
	if(x==n+1&&p[n]!=p[1]){
		ok=1;
		return ;
	}
	if(x==n+1) return ;
	if(vst[x][qaq]) return ;
	if(a[x]!=p[x-1]) p[x]=a[x],dfs(x+1,qaq);
	if(ok) return ;
	if(b[x]!=p[x-1]) p[x]=b[x],dfs(x+1,qaq);
	if(ok) return ;
	if(c[x]!=p[x-1]) p[x]=c[x],dfs(x+1,qaq);
	vst[x][qaq]=1;
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(t);
	while(t--){
		rd(n);ok=0;
		for(int i=1;i<=n+1;i++) vst[i][1]=vst[i][2]=vst[i][3]=0;
		for(int i=1;i<=n;i++) rd(a[i]);
		for(int i=1;i<=n;i++) rd(b[i]);
		for(int i=1;i<=n;i++) rd(c[i]);
		p[1]=a[1];dfs(2,1);
		if(!ok) p[1]=b[1];dfs(2,2);
		if(!ok) p[1]=c[1];dfs(2,3);
		for(int i=1;i<=n;i++) wr(p[i]),putchar(' ');puts("");
	}
	return 0;
}