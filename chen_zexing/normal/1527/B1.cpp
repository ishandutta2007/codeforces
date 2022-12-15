#include <stdio.h>
#include<iostream>
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
#define hash hassh
using namespace std;
char s[1005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int cnt=0,f=0;
        for(int i=1;i<=n/2;i++) cnt+=s[i]=='0';
        f=(n%2&&s[n/2+1]=='0');
        if(f){
            if(cnt) puts("ALICE");
            else puts("BOB");
        }
        else{
            puts("BOB"); 
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp