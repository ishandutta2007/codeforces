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
int a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,c0=0;
        scanf("%d",&n);
        map <int,int> mp,nxt;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mp[a[i]]++;
        }
        for(int i=1;i<n;i++){
            nxt.clear();
            int pre=-1;
            for(auto t:mp) {
                if (t.second > 1) nxt[0] += t.second - 1;
                if (pre != -1) nxt[t.first - pre]++;
                pre=t.first;
            }
            swap(mp,nxt);
            if(mp.size()==1) break;
        }
        printf("%d\n",(*mp.begin()).second>1?0:(*mp.begin()).first);
    }
    return 0;
}
//unordered_map
//cf