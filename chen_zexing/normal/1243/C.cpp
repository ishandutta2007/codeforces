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
long long p[100005];
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        long long n,x=0,o;
        cin>>n;
        if(n==1){
            puts("1");
            continue;
        }
        o=n;
        for(int i=2;1LL*i*i<=n;i++)
            if(n%i==0){
                while(n%i==0) n/=i;
                p[++x]=i;
            }
        if(n>1) p[++x]=n;
        if(x>1) puts("1");
        else{
            printf("%lld\n",p[1]);
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