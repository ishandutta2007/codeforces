#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
long long gcd(long long a,long long b){
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int T = 1;
    //cin >> T;
    while(T--) {
        long long n,m,q;
        cin>>n>>m>>q;
        long long g=gcd(n,m);
        for(int i=1;i<=q;i++){
            long long x1,y1,x2,y2;
            scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
            if(x1==1) y1=(y1-1)/(n/g);
            else y1=(y1-1)/(m/g);
            if(x2==1) y2=(y2-1)/(n/g);
            else y2=(y2-1)/(m/g);
            puts(y1==y2?"YES":"NO");
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//