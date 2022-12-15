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
int f[10005];
vector <int> prime;
int cnt[20000005];
int solve(int c,int d,int v){
    v+=d;
    if(v%c) return 0;
    v/=c;
    return (1<<cnt[v]);
}
int main() {
    for(int i=2;i<=20000000;i++) {
        if(cnt[i]) continue;
        for(int j=i;j<=20000000;j+=i) cnt[j]++;
    }
    int T=1;
    cin>>T;
    while(T--) {
        int c,d,x;
        scanf("%d%d%d",&c,&d,&x);
        long long ans=0;
        for(int i=1;i*i<=x;i++){
            if(x%i==0){
                ans+=solve(c,d,x/i);
                if(i*i!=x) ans+=solve(c,d,i);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//