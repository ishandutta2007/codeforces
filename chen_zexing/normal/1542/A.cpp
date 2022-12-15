#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int cnt[5];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cnt[0]=cnt[1]=0;
        int n;
        cin>>n;
        for(int i=1,x;i<=n*2;i++) scanf("%d",&x),cnt[x%2]++;
        puts(cnt[0]==cnt[1]?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//