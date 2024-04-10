#pragma GCC optimize("Ofast,unroll-loops")
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
#include <assert.h>
#include <random>
using namespace std;
int a[205];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
        sort(a+1,a+n*2+1);
        int f=1;
        for(int i=1;i<=n;i++) if(a[i]+x>a[i+n]) f=0;
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map
//cf