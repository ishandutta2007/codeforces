#include<cstdio>
using namespace std;
int n,ans=10000;bool a[10010][10];long long x;__int128 z;
inline int ws(__int128 v){int res=0;for(;v;v/=10) ++res;return res;}
void dfs(__int128 val,int stp){
	if(stp+n-ws(val)>=ans) return;
	if(val>=z){ans=stp;return;}
	for(int i=0;i<10;++i) a[stp][i]=0;
	for(__int128 v=val;v;v/=10) a[stp][v%10]=1;
	for(int i=9;i>1;--i) if(a[stp][i]) dfs(val*i,stp+1);
}
int main(){
	scanf("%d%lld",&n,&x);
	for(int i=z=1;i<n;++i) z*=10;
	dfs(x,0);
	printf("%d",ans<10000?ans:-1);
	return 0;
}