#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int a[100005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,f[2]={};
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[a[i]%2]=1;
        if(!f[0]||!f[1]){
            for(int i=1;i<=n;i++) printf("%d ",a[i]);
            puts("");
        }
        else{
            sort(a+1,a+n+1);
            for(int i=1;i<=n;i++) printf("%d ",a[i]);
            puts("");
        }
    }
    return 0;
}
//
/// 
//01
//
//!