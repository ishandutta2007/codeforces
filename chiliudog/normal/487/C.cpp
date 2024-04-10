#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/int n;
inline int powmod(int a,int b){
    int res=1;
    for(;b;b>>=1){
        if(b&1)res=1ll*res*a%n;a=1ll*a*a%n;
    }return res;
}
const int maxn=100005;
bool app[maxn];
int main(){
    // judge();
    read(n);
    if(n==4){
        printf("YES\n1\n3\n2\n4");
        return 0;
    }
    rep(i,2,n-1){
        if(n%i==0){
            puts("NO");
            return 0;
        }
    }puts("YES");
    printf("%d\n",1);
    rep(i,2,n-1){
        int v=1ll*i*powmod(i-1,n-2)%n;
        // if(app[v]){
            // puts
            // assert(0);
        // }app[v]=1;
        printf("%d\n",v);
    }if(n!=1)printf("%d\n",n);
    return 0;
}