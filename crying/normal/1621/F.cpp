#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
ll T,n,a,b,c,ans,tot,s0,s1,cnt0,cnt1;
array<int,2>d[MAXN];
int arr[MAXN],len;
string s;
void upd(ll& x,ll y){x=max(x,y);}
ll calc(ll s0,ll op1,ll cnt0){
    ll op0=s0-cnt0;
    if(op0>op1)return (a+b)*op1+a;
    if(op0==op1)return (a+b)*op1;
    if(c>=b)return (a+b)*op0;
    if(s0>=op1)return a*op0+b*op1-c*(op1-op0);
    return a*op0+b*s0-c*cnt0;
}
void solve(){
    cin>>n>>a>>b>>c>>s;
    s=" "+s;
    ans=tot=0;int cnt=1;
    s0=s1=cnt0=cnt1=0;
    rep(i,2,n){
        if(s[i]!=s[i-1]){
            d[++tot]={cnt,s[i-1]-'0'};
            cnt=1;
        }else cnt++;
    }
    d[++tot]={cnt,s[n]-'0'};
    if(tot==1){
        if(d[1][0]>1){
            if(d[1][1]==0)cout<<a<<endl;
            else cout<<b<<endl;
        }else cout<<0<<endl;
        return;
    }
    len=0;
    rep(i,2,tot-1)if(d[i][1]==0)arr[++len]=d[i][0];
    sort(arr+1,arr+1+len);
    rep(i,1,n)if(s[i]=='0')s0++;else s1++;
    rep(i,1,tot)if(d[i][1]==0)cnt0++;else cnt1++;

    upd(ans,calc(s0,s1-cnt1,cnt0));
    if(s1-cnt1>0)upd(ans,b+calc(s0,s1-cnt1-1,cnt0));

    ll op=s1-cnt1,sum=0;
    rep(i,1,len){
        sum+=arr[i];op++;
        if(op<sum)break;
        upd(ans,a*(sum-i)+b*sum-c*i+calc(s0-sum,op-sum,cnt0-i));
    }  
    if(s1==cnt1){cout<<ans<<endl;return;}

    op=s1-cnt1-1,sum=0;
    rep(i,1,len){
        sum+=arr[i];op++;
        if(op<sum)break;
        upd(ans,b+a*(sum-i)+b*sum-c*i+calc(s0-sum,op-sum,cnt0-i));
    }  
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}