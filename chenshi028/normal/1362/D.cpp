#include<cstdio>
#include<cstring>
#include<vector>
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
const int o=1e6+10;
int n,m,U,V,cnt,h[o],t[o],tag[o],ans[o];vector<int> ind[o];
struct Edge{int v,p;}e[o<<1];
inline void ad(int U,int V){e[++cnt].v=V;e[cnt].p=h[U];h[U]=cnt;}
int main(){
	read(n);read(m);
	for(int i=1;i<=m;++i) read(U),read(V),ad(U,V),ad(V,U);cnt=0;
	for(int i=1;i<=n;++i){read(t[i]);if(t[i]>n){printf("-1");return 0;}ind[t[i]].push_back(i);}
	for(int i=1;i<=n;++i){
		for(int j=0,k;j<ind[i].size();++j){
			for(k=h[ind[i][j]];k;k=e[k].p) tag[t[e[k].v]]=ind[i][j];
			for(k=1;tag[k]==ind[i][j];++k);
			if(k^i){printf("-1");return 0;}
			ans[++cnt]=ind[i][j];
		}
	}
	for(int i=1;i<=n;++i) write(ans[i]),putchar(' ');
	return 0;
}