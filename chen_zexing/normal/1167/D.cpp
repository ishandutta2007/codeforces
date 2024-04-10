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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,cnt=0,now=0,oth=0,mx=0;
        cin>>n;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) s[i]=='('?cnt++:cnt--,mx=max(mx,cnt);
        for(int i=1;i<=n;i++){
            if(s[i]=='('){
                if(now<mx/2) printf("1"),now++;
                else printf("0"),oth++;
            }
            else{
                if(oth) printf("0"),oth--;
                else printf("1"),now--;
            }
        }
    }
    return 0;
}
//
/// 
//01
//