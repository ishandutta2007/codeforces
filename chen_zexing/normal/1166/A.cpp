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
#include <functional>
#define hash hassh
using namespace std;
int cnt[26];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,ans=0;
        cin>>n;
        string s;
        for(int i=1;i<=n;i++) cin>>s,cnt[s[0]-'a']++;
        for(int i=0;i<26;i++) ans+=(cnt[i]/2)*(cnt[i]/2-1)/2+(cnt[i]-cnt[i]/2)*(cnt[i]-cnt[i]/2-1)/2;
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp