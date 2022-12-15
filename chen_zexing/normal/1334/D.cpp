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
void solve(int n,long long l,long long r,int add){
    if(r<=0) return;
    if(l<=(n-1)*2){
        int cnt=0;
        for(int i=2;i<=n;i++){
            cnt++;
            if(cnt>=l&&cnt<=r) printf("%d ",add+1);
            cnt++;
            if(cnt>=l&&cnt<=r) printf("%d ",add+i);
        }
        if(r>cnt) solve(n-1,1,r-cnt,add+1);
    }
    else solve(n-1,l-(n-1)*2,r-(n-1)*2,add+1);
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        long long l,r;
        scanf("%d",&n);
        scanf("%lld%lld",&l,&r);
        solve(n,l,min(r,1LL*n*(n-1)),0);
        if(r>1LL*n*(n-1)) printf("1");
        puts("");
    }
    return 0;
}