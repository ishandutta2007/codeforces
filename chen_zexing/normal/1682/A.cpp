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
char s[100005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        scanf("%s",s+1);
        int l=n/2+1,r=n/2+1;
        while(l>1&&s[l-1]==s[l]) l--;
        while(r<n&&s[r+1]==s[r]) r++;
        printf("%d\n",r-l+1);
    }
    return 0;
}