#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=110;
int T,n,m,k;
char s[MAXN],t[MAXN],ret[MAXN*2];
void solve(){
    cin>>n>>m>>k;
    cin>>(s+1)>>(t+1);memset(ret,0,sizeof ret);
    sort(s+1,s+1+n);
    sort(t+1,t+1+m);
    int tot=0,L=1,R=1,cnt1=0,cnt2=0;
    while(L<=n && R<=m){
        if(cnt1==k){
            cnt1=0;cnt2++;
            ret[++tot]=t[R];R++;
            continue;
        }
        if(cnt2==k){
            cnt1++;cnt2=0;
            ret[++tot]=s[L];L++;
            continue;
        }
        int flag=0;
        if((n-L+1)*k>=m-R+1)flag=1;
        if((m-R)*k+(k-cnt1-1)>=n-L)flag=1;
        int flag2=0;
        if((m-R+1)*k>=n-L+1)flag2=1;
        if((n-L)*k+(k-cnt2-1)>=m-R)flag2=1;
        if( (s[L]<t[R] && flag)  || !flag2){
            cnt1++;cnt2=0;
            ret[++tot]=s[L];L++;
        }else{
            cnt1=0;cnt2++;
            ret[++tot]=t[R];R++;
        }
    }

    cout<<(ret+1)<<'\n';
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}