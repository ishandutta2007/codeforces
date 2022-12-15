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
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int T;
    cin>>T;
    while(T--){
        int a,b,k;
        cin>>a>>b>>k;
        if(a>b) swap(a,b);
        int t=gcd(a,b);
        a/=t,b/=t;
        if(b-1>=1LL*(k-1)*a+1) puts("REBEL");
        else puts("OBEY");
    }
    return 0;
}