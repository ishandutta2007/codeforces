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
int a[200005];
vector <int> v;
long long ans=1,mod=998244353,tot;
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            if(a[i]>n-k)
                tot+=a[i],v.push_back(i);
        }
        for(int i=1;i<v.size();i++) ans=ans*(v[i]-v[i-1])%mod;
        printf("%lld %lld\n",tot,ans);
    }
    return 0;
}