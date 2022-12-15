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
char s[15];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1);
        if(n==2) printf("%c\n",s[2]);
        else{
            int mn=10;
            for(int i=1;i<=n;i++) mn=min(mn,s[i]-'0');
            printf("%d\n",mn);
        }
    }
    return 0;
}
//unordered_map
//cf