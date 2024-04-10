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
int n,t[27]; char s[N];
void print(){
    for(int i=0;i<26;i++) while(t[i]-->0) printf("%c",i+'a');
    puts("");
}
vector<int> v;

int main()
{
    int T=read();
    while(T--){
        v.clear();
        scanf("%s",s+1); n=strlen(s+1);
        for(int i=0;i<26;i++) t[i]=0;
        for(int i=1;i<=n;i++) t[s[i]-'a']++;
        int cnt=0,mi=27;
        for(int i=0;i<26;i++) if(t[i]){
            cnt++; checkmin(mi,i);
            v.push_back(i);
        }
        if(cnt==1){print(); continue;}
        int flag=0;
        for(int i=0;i<26;i++) if(t[i]==1){
            printf("%c",i+'a'); t[i]--;
            print(); flag=1;
            break;
        }
        if(flag) continue;
        if((n-1)/2<=n-t[mi]){
            printf("%c%c",mi+'a',mi+'a'); t[mi]-=2;
            int i=1;
            while(t[mi]){
                if(!t[v[i]]) i++;
                printf("%c",v[i]+'a'); t[v[i]]--;
                printf("%c",mi+'a'); t[mi]--;
            }
            print();
        }
        else{
            printf("%c",mi+'a'); t[mi]--;
            printf("%c",v[1]+'a'); t[v[1]]--;
            if(cnt==2){
                while(t[v[1]]--) printf("%c",v[1]+'a');
                print();
            }
            else{
                // outln(t[mi]); return 0;
                while(t[mi]--) printf("%c",mi+'a');
                printf("%c",v[2]+'a'); t[v[2]]--;
                print();
            }
        }
    }
    return 0;
}