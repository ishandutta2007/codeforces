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
int a[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,cnt=0;
        scanf("%d",&n);
        for(int i=1,x;i<=n;i++) scanf("%d",&x),cnt+=x%2;
        printf("%d\n",min(cnt,n-cnt));
    }
    return 0;
}