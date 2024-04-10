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
int a[205][205],now[205][205];
int r[205],c[205],n,m;
int check(int id){
    int sel=id==1?2:1;
    for(int i=1;i<=m;i++) c[i]=now[sel][i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(c[j]) now[i][j]^=1;
    for(int i=1;i<=n;i++) {
        if(i==id) continue;
        for (int j = 2; j <= m; j++) {
            if(now[i][j]!=now[i][j-1]) return 0;
        }
    }
    int lpos,rpos;
    lpos=1,rpos=m;
    while(lpos<n&&now[id][lpos+1]==now[id][lpos]) lpos++;
    while(rpos>1&&now[id][rpos-1]==now[id][rpos]) rpos--;
    if(lpos<rpos-1) return 0;
    return 1;
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]);
        if(n==1){
            puts("YES");
            puts("0");
            for(int i=1;i<=m;i++) printf("%d",a[1][i]);
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                for(int k=1;k<=m;k++)
                    now[j][k]=a[j][k];
            if(check(i)){
                for(int j=1;j<=i;j++) r[j]=now[j][1];
                for(int j=i+1;j<=n;j++) r[j]=now[j][1]^1;
                puts("YES");
                for(int j=1;j<=n;j++) printf("%d",r[j]);
                puts("");
                for(int j=1;j<=m;j++) printf("%d",c[j]);
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