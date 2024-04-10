#include<cstdio>
using namespace std;
template<class T>inline void read(T&a)
{char c=getchar();int f=1;a=0;for(;c>'9'||c<'0';c=getchar()) if(c=='-') f=-1;for(;c<='9'&&c>='0';c=getchar()) a=a*10+c-48;a*=f;}
inline int Min(int a,int b){return a<b?a:b;}
inline int Max(int a,int b){return a>b?a:b;}
const int o=15010,O=300;
int T,n,a[o],fl[o][O],fr[o][O],ans;
struct fenwicktree{
	int b[o];
	inline void init(int val){for(int i=0;i<=n+1;++i) b[i]=val;}
	inline int lowbit(int x){return x&-x;}
	inline void modify1(int pos,int dir,int val){
		if(dir==-1) pos=n+1-pos;
		if(!pos) return;
		for(;pos<=n+1;pos+=lowbit(pos)) b[pos]=Min(b[pos],val);
	}
	inline void modify2(int pos,int dir,int val){
		if(dir==-1) pos=n+1-pos;
		if(!pos) return;
		for(;pos<=n+1;pos+=lowbit(pos)) b[pos]=Max(b[pos],val);
	}
	inline int query1(int pos,int dir){
		if(dir==1) pos=n+1-pos;
		int res=n+1;
		for(;pos;pos-=lowbit(pos)) res=Min(res,b[pos]);
		res=Min(res,b[pos]);
		return res;
	}
	inline int query2(int pos,int dir){
		if(dir==1) pos=n+1-pos;
		int res=0;
		for(;pos;pos-=lowbit(pos)) res=Max(res,b[pos]);
		res=Max(res,b[pos]);
		return res;
	}
}l0[O],r0[O],l1[O],r1[O];
int main(){
	for(read(T);T--;printf("%d\n",ans),ans=0){
		read(n);
		for(int i=1;i<=n;++i) read(a[i]);
		for(int i=0;i<O;++i) l0[i].init(n+1),r0[i].init(n+1),l1[i].init(0),r1[i].init(0);
		for(int i=1;i<=n;++i) for(int j=1;j<O;++j) fl[i][j]=n+1,fr[i][j]=0;
		fl[n][1]=fr[n][1]=a[n];
		for(int i=n-1;i;--i)
			for(int j=2;j<O;++j){
				l0[j-1].modify1(a[i+1],-1,fl[i+1][j-1]),r1[j-1].modify2(a[i+1],1,fr[i+1][j-1]);
				if(i+j-1<=n) l1[j-1].modify2(fl[i+j-1][j-1],1,a[i+j-1]),r0[j-1].modify1(fr[i+j-1][j-1],-1,a[i+j-1]);
				fl[i][j]=Min(l0[j-1].query1(a[i]+1,1),r0[j-1].query1(a[i]+1,1));
				fr[i][j]=Max(r1[j-1].query2(a[i]-1,-1),l1[j-1].query2(a[i]-1,-1));
			}
		for(int i=1;i<=n;++i) for(int j=1;j<O;++j){
			if(fl[i][j]<=n) ans=Max(ans,j);
			if(fr[i][j]) ans=Max(ans,j);
		}
		for(int i=0;i<O;++i) l0[i].init(n+1),r0[i].init(n+1),l1[i].init(0),r1[i].init(0);
		for(int i=1;i<=n;++i) for(int j=1;j<O;++j) fl[i][j]=n+1,fr[i][j]=0;
		for(int i=1;i<=n;++i) fl[i][2]=fr[i][2]=a[i];
		for(int i=n-1;i;--i)
			for(int j=3;j<O;++j){
				l0[j-1].modify1(a[i+1],-1,fl[i+1][j-1]),r1[j-1].modify2(a[i+1],1,fr[i+1][j-1]);
				if(i+j-1<=n) l1[j-1].modify2(fl[i+j-1][j-1],1,a[i+j-1]),r0[j-1].modify1(fr[i+j-1][j-1],-1,a[i+j-1]);
				fl[i][j]=Min(l0[j-1].query1(a[i]+1,1),r0[j-1].query1(a[i]+1,1));
				fr[i][j]=Max(r1[j-1].query2(a[i]-1,-1),l1[j-1].query2(a[i]-1,-1));
			}
		for(int i=1;i<=n;++i) for(int j=1;j<O;++j){
			if(fl[i][j]<=n) ans=Max(ans,j-1);
			if(fr[i][j]) ans=Max(ans,j-1);
		}
	}
	return 0;
}