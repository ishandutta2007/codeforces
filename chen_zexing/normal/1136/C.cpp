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
int a[505][505],b[505][505];
map <int,int> mp;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,f=1;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&b[i][j]);
        for(int i=2;i<=n+m;i++){
            mp.clear();
            for(int j=1;j<i;j++){
                int k=i-j;
                if(j>n||k>m||j<1||k<1) continue;
                mp[a[j][k]]++,mp[b[j][k]]--;
            }
            for(int j=1;j<i;j++){
                int k=i-j;
                if(j>n||k>m||j<1||k<1) continue;
                if(mp[a[j][k]]||mp[b[j][k]]) f=0;
            }
        }
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//