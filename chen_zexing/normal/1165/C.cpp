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
char s[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        scanf("%s",s+1);
        vector <char> ans;
        int f=0;
        char now;
        for(int i=1;i<=n;i++){
            if(!f) now=s[i],f=1;
            else{
                if(now==s[i]) continue;
                else{
                    ans.push_back(now),ans.push_back(s[i]);
                    f=0;
                }
            }
        }
        printf("%d\n",n-ans.size());
        for(auto c:ans) printf("%c",c);
    }
    return 0;
}
//
/// 
//01
//