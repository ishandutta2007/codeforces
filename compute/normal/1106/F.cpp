#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef long long ll;
struct Matrix{
    long long m[100][100];
    void init()
    {
        memset(m,0,sizeof(m));
        for(int i=0;i<100;i++) m[i][i]=1;
    }
    Matrix operator *(const Matrix & a)const{
        Matrix ret;
        memset(ret.m,0,sizeof(ret.m));
        for(int i=0;i<100;i++)
        {
            for(int j=0;j<100;j++)
            {
                for(int k=0;k<100;k++)
                {
                    ret.m[i][j]=(ret.m[i][j]+m[i][k]*a.m[k][j]%(mod-1))%(mod-1);
                }
            }
        }
        return ret;
    }
};
Matrix quick(Matrix a,long long b)
{
    Matrix ret;
    ret.init();
    while(b)
    {
        if(b&1) ret=ret*a;
        a=a*a;
        b>>=1;
    }
    return ret;
}
map<ll, ll> mp;
ll pow(ll a, ll b, ll p) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % p;
        b >>= 1;
        a = a * a % p;
    }
    return ans;
}
ll BSGS(ll A, ll B, ll C) {
    mp.clear();
    if(A % C == 0) return -2;
    ll m = ceil(sqrt(C));
    ll ans;
    for(int i = 0; i <= m; i++) {
        if(i == 0) {
            ans = B % C;
            mp[ans] = i;
            continue;
        }
        ans = (ans * A) % C;
        mp[ans] = i;
    }
    ll t = pow(A, m, C); 
    ans = t;
    for(int i = 1; i <= m; i++) {
        if(i != 1)ans = ans * t % C;
        if(mp.count(ans)) {
            int ret = i * m % C - mp[ans] % C;
            return (ret % C + C)%C;
        }
    }
    return -2;
}
ll extend_gcd(long long a,long long b,long long &x,long long &y)
{
    if(a==0&&b==0) return -1;
    if(b==0){x=1;y=0;return a;}
    long long d=extend_gcd(b,a%b,y,x);
    y-=a/b*x;
    return d;
}
long long brr[105];
Matrix base;
int main()
{
    int k;
    scanf("%d",&k);
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&brr[i]);
        base.m[0][i]=brr[i];
        if(i!=k-1) base.m[i+1][i]=1;
    }
    int n,m;
    scanf("%d%d",&n,&m);
    Matrix A=quick(base,n-k);
    long long hn=BSGS(3,m,mod);
    long long a=A.m[0][0];
    long long c=0;
    for(int i=1;i<k;i++)
        c=(c+A.m[0][i])%(mod-1);
    //hn=(hn-c+mod-1)%(mod-1);
    long long p=mod-1;
    long long x,y;
    long long gcd=extend_gcd(a,p,x,y);
    if(hn%gcd!=0) puts("-1");
    else{
        x+=p;
        x%=p;
        x=x*(hn/gcd)%p;
        printf("%lld\n",pow(3,x,mod));
    }
}