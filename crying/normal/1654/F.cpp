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
const int MAXN=(1<<18)+10,MAXM=20;
int n,m;
int rk[MAXN*2],oldrk[MAXN*2],cnt[MAXN],tmp[MAXN],sa[MAXN];
char s[MAXN];

int main(){
    cin>>n>>s;
    m=max((1<<n),150);
    rep(i,0,(1<<n)-1)rk[i]=s[i];
    rep(i,0,(1<<n)-1)cnt[rk[i]]++;
    rep(i,1,m)cnt[i]+=cnt[i-1];
    per(i,(1<<n)-1,0)sa[--cnt[rk[i]]]=i;
    rep(i,1,n){
        memset(cnt,0,sizeof cnt);
        int p=0;
        rep(j,0,(1<<n)-1)tmp[p++]=sa[j]^(1<<i-1);
        rep(j,0,(1<<n)-1)cnt[rk[tmp[j]]]++;
        rep(j,1,m)cnt[j]+=cnt[j-1];
        per(j,(1<<n)-1,0)sa[--cnt[rk[tmp[j]]]]=tmp[j];
        rep(j,0,(1<<n)-1)oldrk[j]=rk[j];
        p=1;rk[sa[0]]=1;
        rep(j,1,(1<<n)-1){
            if(oldrk[sa[j]]==oldrk[sa[j-1]] && oldrk[sa[j]^(1<<i-1)]==oldrk[sa[j-1]^(1<<i-1)]){
                rk[sa[j]]=p;
            }else{
                rk[sa[j]]=++p;
            }
        }
    }
    int val=sa[0];
    rep(i,0,(1<<n)-1)cout<<s[i^val];
    return 0;
}