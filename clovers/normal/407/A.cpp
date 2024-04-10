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
const int N=1005;
vector<pii> v[N*N*2];
int a,b;

void solve(int a,int b,int c){
    for(auto &u1 : v[a]){
        for(auto &u2 : v[b]){
            for(auto &u3 : v[c]){
                int x=u1.first+u2.first+u3.first;
                int y=u1.second+u2.second+u3.second;
                if(!x&&!y){
                    puts("YES");
                    pii now=mk(0,0);
                    printf("%d %d\n",now.first,now.second);
                    now.first+=u1.first; now.second+=u1.second;
                    printf("%d %d\n",now.first,now.second);
                    now.first+=u2.first; now.second+=u2.second;
                    printf("%d %d\n",now.first,now.second);
                    exit(0);
                }
            }
        }
    }
}

int main()
{
    a=read(); b=read();
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=2000;j++){
            int t=i*i+j*j;
            if(t>2000000) continue;
            v[t].push_back(mk(i,j)); v[t].push_back(mk(-i,-j));
            v[t].push_back(mk(-i,j)); v[t].push_back(mk(i,-j));
        }
    }
    a=a*a; b=b*b; if(a<b) swap(a,b);
    int c=a+b; solve(a,b,c);
    c=a-b; solve(a,b,c);
    puts("NO");
    return 0;
}