#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2000;
int n=1200,p[N],tot,num,T,re;bool vis[N];LL dat=1,ou;
int query(LL x){printf("? %lld\n",x);cout.flush();re--;int y;scanf("%d",&y);return y;}
void solve(){
    re=22;int now=1;ou=1;
    while(re){
        dat=1;while(1.0*dat*p[now]<1e18)dat*=p[now],now++;
        LL ans=query(dat);
        for(int i=1;i<now;i++)if(ans%p[i]==0&&re){
            LL dd=1;
            while(1.0*p[i]*dd<1e18)dd*=p[i];
            LL pp=query(dd),num=0;
            while(pp%p[i]==0)num++,pp/=p[i];
            ou*=num+1;
        }
    }
    cout<<"! "<<ou*2<<endl;cout.flush();
}
int main(){
    for(int i=2;i<=n;i++){
        if(!vis[i])p[++tot]=i;
        for(int j=i*i;j<=n;j+=i)vis[j]=1;
    }
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}