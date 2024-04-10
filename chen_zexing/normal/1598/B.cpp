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
int a[1005][6];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=0;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=5;j++)
                scanf("%d",&a[i][j]);
        if(n%2){
            puts("NO");
            continue;
        }
        for(int i=1;i<=5;i++)
            for(int j=i+1;j<=5;j++){
                int fl=1,c1=0,c2=0;
                for(int k=1;k<=n;k++){
                    if(a[k][i]==0&&a[k][j]==0) fl=0;
                    if(a[k][i]) c1++;
                    if(a[k][j]) c2++;
                }
                if(fl&&min(c1,c2)>=n/2) f=1;
            }
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//