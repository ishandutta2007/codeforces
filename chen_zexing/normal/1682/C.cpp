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
#include <assert.h>
#include <random>
using namespace std;
int a[200005];
map <int,int> mp;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,cnt;
        scanf("%d",&n),cnt=n;
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]++;
            if(mp[a[i]]>2) cnt--;
        }
        printf("%d\n",(cnt+1)/2);
    }
    return 0;
}