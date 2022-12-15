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
vector <int> v;
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n,now=1;
        cin>>n;
        for(int i=1;i<n-1;i++) if(gcd(i,n)==1) v.push_back(i),now=1LL*now*i%n;
        if(now==n-1) v.push_back(n-1);
        printf("%d\n",v.size());
        for(int i=0;i<v.size();i++) printf("%d ",v[i]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp