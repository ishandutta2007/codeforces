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
using namespace std;
long long a[35],can[100];
int cnt[100],x;
int check(long long a){
    int now=x;
    while(now){
        while(now&&a<can[now]) now--;
        if(now==0) break;
        a-=can[now];
        cnt[now]++;
        now--;
        //cout<<a<<" "<<now<<endl;
    }
    if(a) return 0;
    return 1;
}
int check2(){
    for(int i=1;i<=x;i++)
        if(cnt[i]>1){
            //cout<<i<<" "<<cnt[i]<<endl;
            return 0;
        }
    return 1;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        memset(cnt,0,sizeof(cnt));
        long long n,k;
        scanf("%lld%lld",&n,&k);
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        x=0;
        for(long long i=1;i<=1e16;i*=k){
            can[++x]=i;
        }
        int f=1;
        for(int i=1;i<=n;i++)
            if(!check(a[i])){
                //cout<<i<<endl;
                f=0;
            }
        if(f&&check2()) puts("YES");
        else puts("NO");
    }
    return 0;
}