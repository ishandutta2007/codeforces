//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define register
using namespace std;
#define int long long
// const long long Inf=2e18;
#define pii pair <int, int> 
#define i64 long long
using namespace std;
inline int read(void) {
	register int x=0,sgn=1,ch=getchar();
	while(ch<48||57<ch) {if(ch==45)sgn=0;ch=getchar();}
	while(47<ch&&ch<58) {x=x*10+ch-48;   ch=getchar();}
	return sgn? x:-x;
}
void write(int x) {
    if(x<0) putchar('-'),x=-x;
    if(x>9) write(x/10);
    putchar(x%10+'0');
}
const int p=998244353;
i64 ksm(i64 x,i64 a) {  // Please make sure that 0 <= x <= p-1
    if(a==0) return 1;
    if(a==1) return x;
    i64 tmp=ksm(x,a>>1);
    tmp=tmp*tmp%p;
    (a&1) && (tmp=tmp*x%p);
    return tmp;
}
namespace Inversion {

const int N=400000;

i64 fac[N+2],ifc[N+2];

inline void init(int L=N) {  // Please make sure that L <= N
    fac[0]=1;
    for(int i=1; i<=L; ++i) fac[i]=fac[i-1]*i%p;
    ifc[L]=ksm(fac[L],p-2);
    for(int i=L; i>=1; --i) ifc[i-1]=ifc[i]*i%p;
}

inline i64 C(int a,int b) {  // C(a,b), with check
    if(b>a||b<0) return 0;
    return fac[a]*ifc[b]%p*ifc[a-b]%p;
}

inline i64 P(int x,int y) {  //C(x+y,x), without check
    return fac[x+y]*ifc[x]%p*ifc[y]%p;
}

}  // namespace Inversion
using namespace Inversion;
int n,Ans,res;
char s[100005][2];
int lb,rb,lw,rw;
int ct,cy;
signed main() {
    init();
	n=read(); res=1;
    for(int i=1; i<=n; ++i) {
        scanf("%s",s[i]);
        if(s[i][0]=='B') ++lb;
        if(s[i][0]=='W') ++lw;
        if(s[i][0]=='?') ++cy;
        if(s[i][1]=='B') ++rb;
        if(s[i][1]=='W') ++rw;
        if(s[i][1]=='?') ++cy;
        if(s[i][0]==s[i][1]) {
            if(s[i][0]=='?') res=res*2%p;
            else ++ct;
        }
    }
    Ans=C(cy,(n-lb-rb));
    if(lb==0&&rw==0) ++Ans;
    if(lw==0&&rb==0) ++Ans;
    if(!ct) Ans=(Ans-res+p)%p;
    write(Ans); puts("");
	return 0;
}