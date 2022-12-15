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
long long a[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        long long tot=a[1],ans=0;
        for(int i=2;i<=n;i++){
            if(tot<ceil(double(a[i])*100/k)) ans+=ceil(double(a[i])*100/k-tot),tot=ceil(double(a[i])*100/k);
            tot+=a[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}