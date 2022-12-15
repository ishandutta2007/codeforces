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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
char s[300005];
int pre[300005],a[300005];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,q;
        cin>>n>>q;
        scanf("%s",s+1);
        for(int i=1;i<=n;i++) a[i]=(s[i]=='+'?1:-1),pre[i]=i%2?pre[i-1]+a[i]:pre[i-1]-a[i];
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d",&l,&r);
            int temp=abs(pre[r]-pre[l-1]);
            if(temp%2) printf("1\n");
            else if(temp==0) puts("0");
            else printf("2\n");
        }
    }
    return 0;
}
//
/// 
//01
//