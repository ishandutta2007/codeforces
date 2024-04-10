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
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        long long ans=2;
        int w,h;
        cin>>w>>h;
        long long mod=998244353;
        for(int i=1;i<=w;i++) ans=ans*2%mod;
        for(int i=2;i<=h;i++) ans=ans*2%mod;
        cout<<ans<<endl;
    }
    return 0;
}