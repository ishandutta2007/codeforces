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
const ll INF=(ll)2e18;
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
const int N=100005;
int n; vector<int> v1,v2;
char s[N];

int main()
{
    scanf("%s",s+1); n=strlen(s+1);
    int now=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='_'){now++; continue;}
        else{
            int cnt=0;
            while(s[i]=='#') i++,cnt++;
            v1.push_back(cnt);
            v2.push_back(now-1);
            now=0;
        }
    }
    if(!sz(v1)){puts("0"); return 0;}
    if(s[n]=='_') now++;
    vector<int> ans;
    for(int r=0;r<=now;r++){
        if(r==now-1) continue;
        int flag=1;
        for(int i=0;i<sz(v1);i++){
            int kk=v2[i]-r;
            if(kk<-1){puts("-1"); return 0;}
            int tmp=(kk==-1);
            if(r) tmp|=((kk&1)||(r>=2&&kk>=2));
            flag&=(kk==-1||tmp);
        }
        int kk=now-r-1;
        int tmp=(kk==-1);
        if(r) tmp|=((kk&1)||(r>=2&&kk>=2));
        flag&=(kk==-1||tmp);

        if(flag){
            for(int i=0;i<sz(v1);i++){
                int kk=v2[i]-r;
                if(kk!=-1){
                    if(kk%2==0) kk-=3,ans.push_back(2);
                    while(kk>=1) kk-=2,ans.push_back(1); 
                }
                ans.push_back(v1[i]+r);
            }
            int kk=now-r-1;
            if(kk!=-1){
                if(kk%2==0) kk-=3,ans.push_back(2);
                while(kk>=1) kk-=2,ans.push_back(1); 
            }
            break;
        }
    }
    if(sz(ans)){
        printf("%d\n",sz(ans));
        for(auto &u : ans) printf("%d ",u);
    }
    else puts("-1");
    return 0;
}