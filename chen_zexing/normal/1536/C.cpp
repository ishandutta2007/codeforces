#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
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
int pre[500005];
map <double,int> mp;
char s[500005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        mp.clear();
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(s[i]=='D') pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1]-1;
            mp[double(pre[i])/i]++;
            printf("%d ",mp[double(pre[i])/i]);
        }
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp