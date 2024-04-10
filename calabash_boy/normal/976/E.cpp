//
// Created by calabash_boy on 18-4-30.
//
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN = 2e5+200;
typedef long long LL;
typedef pair<LL,LL> PLL;
LL n,a,b;
priority_queue<PLL> pque;
LL hp[MAXN],dmg[MAXN];
LL gain[MAXN];
LL ans=0;
bool used[MAXN];
void input(){
    cin>>n>>a>>b;
    for(LL i=0;i<n;i++) {
        scanf("%I64d%I64d",&hp[i],&dmg[i]);
        ans+=dmg[i];
    }
}
void solve(){
    for(LL i=0;i<n;i++) {
        LL t=hp[i]<<a;
        gain[i]=t>dmg[i]?t-dmg[i]:0;
    }
    for(LL i=0;i<n;i++)
        if(hp[i]>dmg[i]) pque.push(PLL(hp[i]-dmg[i],i));
    memset(used,false,sizeof(used));
    if(b==0) {
        printf("%I64d\n",ans);
        return ;
    }
    LL least=0;
    while(b>0&&pque.size()) {
        PLL p=pque.top();
        pque.pop();
        ans+=p.F;used[p.S]=true;
        b--;
        if(b==0) least=p.F;
    }
    LL res=0;
    if(b>0) {
        for(LL i=0;i<n;i++)
        {
            LL q=hp[i]>dmg[i]?gain[i]-(hp[i]-dmg[i]):gain[i];
            if(q>res) res=q;
        }
        ans+=res;
        printf("%I64d\n",ans);
    } else {
        for(LL i=0;i<n;i++)
        {
            LL q=(hp[i]>dmg[i]&&used[i])?gain[i]-(hp[i]-dmg[i]):gain[i]-least;
            if(q>res) res=q;
        }
        ans+=res;
        printf("%I64d\n",ans);
    }
}
int main() {
    input();
    solve();
    return 0;
}