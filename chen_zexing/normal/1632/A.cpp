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
        scanf("%s",s+1);
        puts(n<=1||n==2&&s[1]!=s[2]?"YES":"NO");
    }
    return 0;
}
//unordered_map