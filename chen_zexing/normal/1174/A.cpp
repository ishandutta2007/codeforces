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
int a[2005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,s1=0,s2=0;
        cin>>n;
        for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n*2;i++) i>n?s2+=a[i]:s1+=a[i];
        if(s1!=s2){
            for(int i=1;i<=n*2;i++) printf("%d ",a[i]);
            puts("");
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=n+1;j<=n*2;j++)
                if(a[i]!=a[j]){
                    swap(a[i],a[j]);
                    for(int k=1;k<=n*2;k++) printf("%d ",a[k]);
                    puts("");
                    return 0;
                }
        puts("-1");
    }
    return 0;
}
//
/// 
//01
//
//!