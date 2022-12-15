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
int a[105],ans[105],n;
int query(){
    printf("? ");
    for(int i=1;i<=n;i++) printf("%d ",a[i]);
    puts("");
    fflush(stdout);
    int t;
    scanf("%d",&t);
    return t;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<n;i++){
            for(int j=1;j<n;j++) a[j]=i;
            a[n]=n;
            int temp=query();
            if(temp){
                ans[n]=i;
                break;
            }
        }
        if(!ans[n]) ans[n]=n;
        for(int i=1;i<=n;i++){
            if(i==ans[n]) continue;
            for(int j=1;j<n;j++) a[j]=ans[n];
            a[n]=i;
            int temp=query();
            ans[temp]=i;
        }
        printf("! ");
        for(int i=1;i<=n;i++) printf("%d ",ans[i]);
    }
    return 0;
}
//
/// 
//01
//