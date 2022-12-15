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
long long gcd(long long a,long long b){
    return a%b==0?b:gcd(b,a%b);
}
int check(long long x){
    long long s=0,t=x;
    while(t) s+=t%10,t/=10;
    if(x<s) swap(x,s);
    //cout<<s<<" "<<x<<gcd(s,x)<<endl;
    return gcd(x,s)>1;
}
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        long long x;
        scanf("%lld",&x);
        while(!check(x)) x++;
        printf("%lld\n",x);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp