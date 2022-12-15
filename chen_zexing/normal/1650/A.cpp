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
char s[55],c[5];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=0;
        scanf("%s",s+1),n=strlen(s+1);
        scanf("%s",c+1);
        for(int i=1;i<=n;i++) if(s[i]==c[1]&&i%2) f=1;
        puts(f?"YES":"NO");
    }
    return 0;
}
//unordered_map