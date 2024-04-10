#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=310;
int T,n,m,st[o],b[o],ans;
struct aud{int a,id;}au[o];
inline bool cmp(aud A,aud B){if(A.a^B.a) return A.a<B.a;return A.id>B.id;}
inline int lowbit(int x){return x&-x;}
inline void modify(int pos){for(;pos<=m;pos+=lowbit(pos)) ++b[pos];}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res+=b[pos];return res;}
int main(){
	for(read(T);T--;printf("%d\n",ans)){
		read(n);read(m);ans=0;
		for(int i=1;i<=m;++i) read(au[i].a),au[i].id=i,b[i]=0;
		sort(au+1,au+1+m,cmp);
		for(int i=1;i<=m;++i) st[au[i].id]=i;
		for(int i=1;i<=m;++i) ans+=query(st[i]),modify(st[i]);
	}
	return 0;
}