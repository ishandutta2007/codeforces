#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[55],n;
void solve(){
    int cnt=0;
    for(int i=1;i<=n;i++) if(a[i]>1) cnt++;
    if(cnt<n/2){
        puts("Bob");
        return;
    }
    if(cnt<n){
        puts("Alice");
        return;
    }
    for(int i=1;i<=n;i++) a[i]--;
    solve();
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        solve();
    }
    return 0;
}
//
/// 
//01
//