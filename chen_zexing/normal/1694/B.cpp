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
#include <assert.h>
#include <random>
using namespace std;
char s[200005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        scanf("%d",&n);
        scanf("%s",s+1);
        for(int i=1;i<=n;i++){
            if(i==1||s[i]==s[i-1]) ans++;
            else ans+=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//cf