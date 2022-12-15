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
int a[105];
char s[105];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1,t;i<=n;i++){
            scanf("%d",&t),scanf("%s",s+1);
            for(int j=1;j<=t;j++) s[j]=='U'?a[i]--:a[i]++;
        }
        for(int i=1;i<=n;i++) printf("%d%c",(a[i]%10+10)%10,i==n?'\n':' ');
    }
    return 0;
}
//unordered_map
//cf