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
map <long long,int> mp;
int main() {
    for(int i=1;1LL*i*i*i<=1e12;i++) mp[1LL*i*i*i]=1;
    int T=1;
    cin>>T;
    while(T--){
        long long n;
        scanf("%lld",&n);
        int f=0;
        for(int i=1;1LL*i*i*i<=n;i++)
            if(mp[n-1LL*i*i*i])
                f=1;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}