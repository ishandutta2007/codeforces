#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=150010,maxw=30;
const int mod=998244353;
ll Pow[maxn];
int i,j,k,n,m,a[maxn];
namespace trie{
    struct node{
        int son[2];
        int Sum;
    }d[maxn*maxw*2];
    int Cnt=1;
    void Insert(int S){
        int now=1;
        for(int i=maxw-1;i>=0;i--){
            int c=!!(S&(1<<i));
            if(!d[now].son[c])d[now].son[c]=++Cnt;
            now=d[now].son[c];
            d[now].Sum++;
        }
    }
    ll work(int rt1,int rt2,int w){
        if(!rt1 || !rt2)return 0;
        if(rt1==rt2){
            if(w<0)return Pow[d[rt1].Sum]-1;
            if(m&(1<<w)){
                return ((Pow[d[d[rt1].son[0]].Sum]-1)+(Pow[d[d[rt1].son[1]].Sum]-1)+work(d[rt1].son[0],d[rt1].son[1],w-1))%mod;
            }else return (work(d[rt1].son[0],d[rt2].son[0],w-1)+work(d[rt1].son[1],d[rt2].son[1],w-1))%mod;
            ll S=work(d[rt1].son[0],d[rt2].son[0],w-1)+work(d[rt1].son[1],d[rt2].son[1],w-1);
            if(m&(1<<w))S+=work(d[rt1].son[0],d[rt2].son[1],w-1);
            return S%mod;
        }else{
            if(w<0)return (Pow[d[rt1].Sum]-1)*(Pow[d[rt2].Sum]-1)%mod;
            if(m&(1<<w)){
                ll S1=work(d[rt1].son[0],d[rt2].son[1],w-1),S2=work(d[rt1].son[1],d[rt2].son[0],w-1);
                return ((S1+1)*(S2+1)%mod-1
                        +(Pow[d[d[rt1].son[0]].Sum]-1)*(Pow[d[d[rt2].son[0]].Sum]-1)%mod
                        +(Pow[d[d[rt1].son[1]].Sum]-1)*(Pow[d[d[rt2].son[1]].Sum]-1)%mod
                        +S1*(Pow[d[d[rt1].son[1]].Sum]+Pow[d[d[rt2].son[0]].Sum]-2)%mod
                        +S2*(Pow[d[d[rt1].son[0]].Sum]+Pow[d[d[rt2].son[1]].Sum]-2)%mod)%mod;
            }else return (work(d[rt1].son[0],d[rt2].son[0],w-1)+work(d[rt1].son[1],d[rt2].son[1],w-1))%mod;
        }
    }
}
int main(){
    Pow[0]=1;for(i=1;i<maxn;i++)Pow[i]=Pow[i-1]*2%mod;
    cin>>n>>m;
    for(i=1;i<=n;i++)scanf("%d",&a[i]),trie::Insert(a[i]);
    cout<<trie::work(1,1,maxw-1)<<endl;
}