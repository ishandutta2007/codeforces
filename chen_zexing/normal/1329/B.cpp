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
#define hash hassh
using namespace std;
int main() {
    long long ans=1;
    int n;
    int m,d;
    int T;
    cin>>T;
    while(T--){
        cin>>m>>d;
        ans=1;
        if(m==1){
            printf("%lld\n",ans%d);
            continue;
        }
        long long now=1;
        while(now*2<=m){
            ans*=now+1;
            ans%=d;
            now*=2;
        }
        now/=2;
        ans=ans*(m-now*2+2)%d-1;
        if(ans<0) ans+=d;
        cout<<ans<<endl;
    }
    return 0;
}