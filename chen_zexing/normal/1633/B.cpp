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
using namespace std;
char s[200005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        scanf("%s",s+1);
        int n=strlen(s+1),cnt0=0,cnt1=0;
        for(int i=1;i<=n;i++) s[i]=='0'?cnt0++:cnt1++;
        if(cnt0==cnt1) printf("%d\n",cnt0-1);
        else printf("%d\n",min(cnt0,cnt1));
    }
    return 0;
}