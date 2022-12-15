#include <stdio.h>
#include<iostream>
#include<string>
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
int main() {
    int T;
    cin>>T;
    while(T--){
        long long a,b,c,d;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a>b*c){
            puts("-1");
            continue;
        }
        long long t=a/(b*d);
        printf("%lld\n",a*(t+1)-t*(t+1)/2*b*d);
    }
    return 0;
}