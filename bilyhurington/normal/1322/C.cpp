/*
 * @Author: BilyHurington
 * @Date: 2020-02-13 19:20:46
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-03-07 18:30:25
 */
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<set>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int T,n,m;
long long val[500010],valp[500010];
vector<int> v[500010];
long long gcd(long long x,long long y){
    if(!y||!x) return x+y;
    if(x%y==0) return y;
    return gcd(y,x%y);
}
const unsigned long long rd=13749173;
map<unsigned long long,int> mp;
unsigned long long Hashing(int x){
    sort(v[x].begin(),v[x].end());
    v[x].erase(unique(v[x].begin(),v[x].end()),v[x].end());
    unsigned long long ans=1;
    for(int i=0;i<v[x].size();i++){
        ans=ans*rd+v[x][i];
    }
    return ans;
}
int main(){
    scanf("%d",&T);
    while(T--){
        mp.clear();
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++) scanf("%lld",&val[i]),v[i].clear();
        int x,y;
        while(m--){
            scanf("%d %d",&x,&y);
            v[y].push_back(x);
        }
        for(int i=1;i<=n;i++) valp[i]=0;
        for(int i=1;i<=n;i++){
            if(!v[i].size()) continue;
            unsigned long long ans=Hashing(i);
            int x=mp[ans];
            if(x) valp[x]+=val[i];
            else valp[i]+=val[i],mp[ans]=i;
        }
        long long ans=0;
        for(int i=1;i<=n;i++) ans=gcd(ans,valp[i]);
        printf("%lld\n",ans);
    }
    return 0;
}