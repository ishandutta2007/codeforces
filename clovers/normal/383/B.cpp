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
const int N=200005;
int n,m,val[N],mm; pii a[N];
vector<int> v[N]; vector<pii> seq;
pii Cross(pii A,pii B){
    return mk(max(A.first,B.first),min(A.second,B.second));
}

int main()
{
    n=read(); m=read();
    if(!m){cout<<n*2-2<<endl; return 0;}
    for(int i=1;i<=m;i++) a[i].first=read(),a[i].second=read();
    sort(a+1,a+m+1);
    for(int i=1;i<=m;i++) val[i]=a[i].first;
    mm=unique(val+1,val+m+1)-val-1;
    for(int i=1;i<=m;i++) 
        a[i].first=lower_bound(val+1,val+mm+1,a[i].first)-val;
    for(int i=1;i<=m;i++) v[a[i].first].push_back(a[i].second);
    for(int i=1;i<=mm;i++){
        if(i==1){
           if(val[i]==1) {seq.push_back(mk(1,v[1][0]-1)); continue;}
           else seq.push_back(mk(1,n));
        } 
        if(val[i]-val[i-1]!=1){
            int l=seq[0].first; 
            seq.clear(); seq.push_back(mk(l,n));
        }
        v[i].push_back(n+1);
        vector<pii> T; T.clear();
        for(int j=0;j<sz(v[i]);j++){
            pii now=(j==0 ? mk(1,v[i][0]-1) : mk(v[i][j-1]+1,v[i][j]-1));
            if(now.first>now.second) continue;
            int l=0,r=sz(seq)-1,mid,best=-1;
            while(l<=r){
                mid=(l+r)>>1;
                pii tmp=Cross(now,seq[mid]);
                if(tmp.first<=tmp.second) best=tmp.first,r=mid-1;
                else{
                    if(seq[mid].first>now.second) r=mid-1;
                    else l=mid+1;
                }
            }
            if(best!=-1) T.push_back(mk(best,v[i][j]-1));
        }
        seq=T; 
        if(seq.empty()){
            puts("-1"); return 0;
        }
    }
    if(val[mm]==n){
        if(seq[sz(seq)-1].second!=n) {puts("-1"); return 0;}
    }
    cout<<2*n-2<<endl;
    return 0;
}