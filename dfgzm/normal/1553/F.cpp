#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=200010,INF=300000;
int i,j,k,n,m,a[maxn];
ll Ans[maxn];
int lowbit(int x){
    return x&(-x);
}
namespace st{
    ll Sum[INF+5],Num[INF+5]; 
    void SumADD(int x,int S){
        for(;x<=INF;x+=lowbit(x))Sum[x]+=S;
    }
    void NumADD(int x,int S){
        for(;x<=INF;x+=lowbit(x))Num[x]+=S;
    }
    ll SumFIND(int x){
        if(!x)return 0;
        ll Ans=0;for(;x;x-=lowbit(x))Ans+=Sum[x];return Ans;
    }
    ll NumFIND(int x){
        if(!x)return 0;
        ll Ans=0;for(;x;x-=lowbit(x))Ans+=Num[x];return Ans;
    }
    ll findSum(int x){
        return SumFIND(x);
    }
    ll findNum(int x){
        return NumFIND(x);
    }
    void addSum(int l,int r,int S){
        SumADD(l,S);SumADD(r+1,-S);
    }
    void addNum(int l,int r,int S){
        NumADD(l,S);NumADD(r+1,-S);
    }
}
namespace st2{
    ll Sum[INF+5],Num[INF+5]; 
    void SumADD(int x,int S){
        for(;x<=INF;x+=lowbit(x))Sum[x]+=S;
    }
    void NumADD(int x,int S){
        for(;x<=INF;x+=lowbit(x))Num[x]+=S;
    }
    ll SumFIND(int x){
        if(!x)return 0;
        ll Ans=0;for(;x;x-=lowbit(x))Ans+=Sum[x];return Ans;
    }
    ll NumFIND(int x){
        if(!x)return 0;
        ll Ans=0;for(;x;x-=lowbit(x))Ans+=Num[x];return Ans;
    }
    ll findSum(int L,int R){
        return SumFIND(R)-SumFIND(L-1);
    }
    ll findNum(int L,int R){
        return NumFIND(R)-NumFIND(L-1);
    }
    void addSum(int x,int S){
        SumADD(x,S);
    }
    void addNum(int x,int S){
        NumADD(x,S);
    }
}
int main(){
    cin>>n;
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    ll Ans=0;
    for(i=1;i<=n;i++){
        // cerr<<"i="<<i<<endl;
        Ans+=st::findSum(a[i])+st::findNum(a[i])*a[i];
        for(int S=1;a[i]*S<=INF;S++){
            int L=a[i]*S,R=a[i]*(S+1)-1;
            R=min(R,INF);
            // ll s1=st2::findSum(L,R),s2=st2::findNum(L,R)*a[i];
            // if(s1-s2){cerr<<"L="<<L<<" R="<<R<<' '<<s1<<' '<<s2<<endl;}
            Ans+=st2::findSum(L,R)-st2::findNum(L,R)*(L-a[i]);
        }
        for(int S=1;a[i]*S<=INF;S++){
            int L=a[i]*S,R=a[i]*(S+1)-1;
            R=min(R,INF);
            st::addNum(L,R,1);
            st::addSum(L,R,a[i]-L);
        }
        st2::addNum(a[i],1);
        st2::addSum(a[i],a[i]);
        printf("%lld\n",Ans);
    }
}