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
unordered_map <long long,int> mp;
int x[200005],y[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            scanf("%d%d",&x[i],&y[i]);
            if(x[i]>y[i]) swap(x[i],y[i]);
            mp[1LL*x[i]*1e9+y[i]]=1;
        }
        for(int i=1;i<n;i++)
            if(n%i==0){
                int f=1;
                for(int j=1;j<=m;j++){
                    int xx=x[j]+i,yy=y[j]+i;
                    if(xx>n) xx-=n;
                    if(yy>n) yy-=n;
                    if(xx>yy) swap(xx,yy);
                    if(!mp[1LL*xx*1e9+yy]){
                        f=0;
                        break;
                    }
                }
                if(f){
                    puts("YES");
                    exit(0);
                }
            }
        puts("NO");
    }
    return 0;
}
//
/// 
//01
//