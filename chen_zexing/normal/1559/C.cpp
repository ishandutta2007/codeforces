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
int a[10005];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int cnt[2]={};
        for(int i=1;i<=n;i++) cnt[a[i]]++;
        if(a[1]==1){
            printf("%d ",n+1);
            for(int i=1;i<=n;i++) printf("%d ",i);
            puts("");
        }
        else if(cnt[0]==n){
            for(int i=1;i<=n+1;i++) printf("%d ",i);
            puts("");
        }
        else{
            for(int i=1;i<=n;i++){
                if(a[i]==0&&a[i+1]==1){
                    for(int j=1;j<=i;j++) printf("%d ",j);
                    printf("%d ",n+1);
                    for(int j=i+1;j<=n;j++) printf("%d ",j);
                    puts("");
                    break;
                }
            }
        }
    }
    return 0;
}
//
/// 
//01
//
//!