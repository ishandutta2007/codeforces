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
const int MAXN=5e5+10,MAXM=1e6+10,LIM=1e6;
int T,n,a[MAXN];
int L[MAXN],R[MAXN],LL[MAXN],RR[MAXN],st[MAXN],top;
int lst[MAXM];
ll ans;
vector<int>d[MAXM];

void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    ans=0;

    top=0;
    rep(i,1,n){
        while(st[top] &&  a[st[top]]>=a[i])top--;
        if(top)L[i]=st[top];else L[i]=0;
        st[++top]=i;
    }
    top=0;
    per(i,n,1){
        while(st[top] && a[st[top]]>=a[i])top--;
        if(top)R[i]=st[top];else R[i]=n+1;
        st[++top]=i;
    }
    top=0;
    rep(i,1,n){
        while(st[top] &&  a[st[top]]<a[i])top--;
        if(top)LL[i]=st[top];else LL[i]=0;
        st[++top]=i;
    }
    top=0;
    per(i,n,1){
        while(st[top] && a[st[top]]<=a[i])top--;
        if(top)RR[i]=st[top];else RR[i]=n+1;
        st[++top]=i;
    }

    memset(lst,0,sizeof lst);
    rep(i,1,n){
        lst[a[i]]=i;
        for(auto v:d[a[i]]){
            if(!lst[v])continue;
            int l=max(L[lst[v]],LL[i]),r=min(R[lst[v]],RR[i]);
            if(l<lst[v] && r>i)ans+=1ll*(lst[v]-l)*(r-i);
        }
    }

    top=0;
    rep(i,1,n){
        while(st[top] &&  a[st[top]]>a[i])top--;
        if(top)L[i]=st[top];else L[i]=0;
        st[++top]=i;
    }
    memset(lst,0,sizeof lst);
    per(i,n,1){
        lst[a[i]]=i;
        for(auto v:d[a[i]]){
            if(!lst[v])continue;
            int l=max(L[lst[v]],LL[i]),r=min(R[lst[v]],RR[i]);
            if(l<i && r>lst[v])ans+=1ll*(i-l)*(r-lst[v]);
        }
    }
    rep(i,1,n){
        int r=min(RR[i],R[i]);
        ans+=r-i;
    }


    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(false);
    rep(i,1,LIM)rep(j,2,LIM)if(i*j>LIM)break;else d[i*j].push_back(i);
    cin>>T;
    while(T--)solve();

    return 0;
}