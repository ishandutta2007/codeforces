#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a){
	char c=getchar();int f=1;a=0;
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0') a=(a<<1)+(a<<3)+c-48,c=getchar();
	a*=f;
}
template<class T>void write(T a){
	if(a<0) putchar('-'),a=-a;
	if(a>9) write(a/10);
	putchar(a%10+48);
}
const int o=2e5+10,MOD=1e9+7;
int n,m,k,U,V,W,h[o],ans,lgl,f[10][10],l;vector<pair<int,int> > e[o];
void dfs(int nw,int len){
	if(nw>k){if(len==lgl) ++ans;return;}
	for(int i=1;i<=nw;++i) dfs(nw+1,(len+f[nw][i])%MOD);
}
int main(){
	read(n);read(m);read(k);
	for(int i=1;i<=m;++i) read(U),read(V),read(W),e[U].push_back(make_pair(W,V));
	lgl=h[1]=1;for(int i=2;i<=n;++i) lgl=(lgl+(h[i]=h[i-1]*2%MOD))%MOD;
	for(int i=1;i<=n;++i) if(l=e[i].size()){sort(e[i].begin(),e[i].end());for(int j=0;j<l;++j) f[l][j+1]=(f[l][j+1]+h[e[i][j].second])%MOD;};
	dfs(1,0);write(ans);
	return 0;
}