#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while(T--) {
        int n,mx=0,mn=INT_MAX;
        cin>>n;
        for(int i=1,x;i<=n;i++) scanf("%d",&x),mn=min(mn,x),mx=max(mx,x);
        printf("%d\n",mx-mn);
    }
    return 0;
}