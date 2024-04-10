/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=998244353;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=205;
int n;
vector<pii> v1,v2;

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if((i+j)&1) v1.push_back(mk(i,j));
            else v2.push_back(mk(i,j));
        }
    }
    for(int rnd=1,i1=0,i2=0;rnd<=n*n;rnd++){
        int x=read();
        if(x!=1&&i1<sz(v1)){
            printf("1 %d %d\n",v1[i1].first,v1[i1].second);
            fflush(stdout);
            i1++;
        }
        else if(x!=2&&i2<sz(v2)){
            printf("2 %d %d\n",v2[i2].first,v2[i2].second);
            fflush(stdout);
            i2++;
        }
        else{
            if(i1<sz(v1)){
                printf("3 %d %d\n",v1[i1].first,v1[i1].second);
                fflush(stdout);
                i1++;
            }
            if(i2<sz(v2)){
                printf("3 %d %d\n",v2[i2].first,v2[i2].second);
                fflush(stdout);
                i2++;
            }
        }
    }
    return 0;
}