#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int a[100005],b[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,x,fl=1;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i];
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++)
            if(i<=x&&n-i<x&&a[i]!=b[i])
                fl=0;
        puts(fl?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//