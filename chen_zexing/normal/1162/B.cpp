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
int a[55][55],b[55][55];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>a[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                cin>>b[i][j];
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++){
                if(i<n&&(min(a[i][j],b[i][j])>=min(a[i+1][j],b[i+1][j])||max(a[i][j],b[i][j])>=max(a[i+1][j],b[i+1][j]))){
                    puts("Impossible");
                    exit(0);
                }
                if(j<m&&(min(a[i][j],b[i][j])>=min(a[i][j+1],b[i][j+1])||max(a[i][j],b[i][j])>=max(a[i][j+1],b[i][j+1]))){
                    puts("Impossible");
                    exit(0);
                }
            }
        puts("Possible");
    }
    return 0;
}
//
/// 
//01
//