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
int cnt[1000005];
int main() {
    long long k,l,r,t,x,y;
    cin>>k>>l>>r>>t>>x>>y;
    if(x==y){
        if(k+y<=r||k-x>=l) puts("Yes");
        else puts("No");
    }
    if(x>y){
        if(k+y<=r){
            if((k-l)/(x-y)>=t) puts("Yes");
            else puts("No");
        }
        else{
            if((k-x-l)/(x-y)>=t-1) puts("Yes");
            else puts("No");
        }
    }
    if(x<y){
        if(k-t*x>=l){
            puts("Yes");
            return 0;
        }
        long long p=y%x;
        long long d=(k-l)%x;
        t-=(k-l)/x;
        long long now=l+d;
        cnt[now%x]=1;
        now+=y;
        if(now>r){
            puts("No");
            return 0;
        }
        while(cnt[now%x]==0){
            if(now-l>=t*x){
                puts("Yes");
                return 0;
            }
            d=(now-l)%x;
            t-=(now-l)/x;
            now=l+d;
            cnt[now%x]=1;
            now+=y;
            if(now>r){
                puts("No");
                return 0;
            }
        }
        puts("Yes");
    }
    return 0;
}