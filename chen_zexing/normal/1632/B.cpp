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
using namespace std;
char s[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        int mx=n-1,now=1;
        while(now*2<=mx) now*=2;
        for(int i=now-1;i>=0;i--) printf("%d ",i);
        for(int i=now;i<n;i++) printf("%d ",i);
        puts("");
    }
    return 0;
}
//unordered_map