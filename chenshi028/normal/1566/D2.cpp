#include<cstdio>
#include<algorithm>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(a=0;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
const int o=310;
int T,n,m,st[o*o],b[o][o],w[o*o],cnt,ans;
struct audience{int a,id;}aud[o*o];
inline int lowbit(int x){return x&-x;}
inline void modify(int id,int pos){for(++pos;pos<=m;pos+=lowbit(pos)) ++b[id][pos];}
inline int query(int id,int pos){int res=0;for(++pos;pos;pos-=lowbit(pos)) res+=b[id][pos];return res;}
inline bool cmp(audience A,audience B){if(A.a^B.a) return A.a<B.a;return A.id>B.id;}
inline bool cmp2(int A,int B){if(A/m-B/m) return A/m>B/m;return A%m<B%m;}
int main(){
	for(read(T);T--;printf("%d\n",ans),ans=0){
		read(n);read(m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j) read(aud[i*m+j].a),aud[i*m+j].id=i*m+j,b[i][j+1]=0;
		sort(aud,aud+n*m,cmp);
		for(int i=0,j;i<n*m;++i){
			for(j=w[cnt=1]=i;j<n*m-1&&aud[j+1].a==aud[j].a;w[++cnt]=++j);
			sort(w+1,w+cnt+1,cmp2);
			for(int $=1,_=i;_<=j;++$,++_) st[aud[_].id]=w[$];
			i=j;
		}
		for(int i=0,j;i<n*m;++i) ans+=query(st[i]/m,st[i]%m),modify(st[i]/m,st[i]%m);
	}
	return 0;
}