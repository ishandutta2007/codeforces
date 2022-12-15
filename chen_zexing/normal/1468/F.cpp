#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
unordered_map <long long,int> mp;
int gcd(int x,int y){
    return y==0?x:gcd(y,x%y);
}
int uu[100005],vv[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++){
            int x,y,u,v;
            scanf("%d%d%d%d",&x,&y,&u,&v);
            u-=x,v-=y;
            int temp=gcd(abs(u),abs(v));
            u/=temp,v/=temp;
            uu[i]=u,vv[i]=v;
            mp[1LL*u*(1000000007)+v]++;
        }
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=mp[-1LL*uu[i]*(1000000007)-vv[i]];
        printf("%lld\n",ans/2);
    }
    return 0;
}