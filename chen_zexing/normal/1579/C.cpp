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
char s[25][25];
int f[25][25],n,m;
int check(int x,int y,int k){
    if(x<=k||y<=k||y+k>m) return 0;
    int cnt1=0,xx=x,yy=y,cnt2=0;
    while(xx&&yy){
        if(s[xx][yy]=='*') xx--,yy--,cnt1++;
        else break;
    }
    xx=x,yy=y;
    while(xx&&yy<=m){
        if(s[xx][yy]=='*') xx--,yy++,cnt2++;
        else break;
    }
    cnt1--,cnt2--;
    if(min(cnt1,cnt2)>=k) return min(cnt1,cnt2);
    else return 0;
}
void color(int x,int y,int k){
    int xx=x,yy=y,kk=k+1;
    while(xx&&yy&&kk--) f[xx--][yy--]=1;
    xx=x,yy=y,kk=k+1;
    while(kk--) f[xx--][yy++]=1;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int k;
        cin>>n>>m>>k;
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        memset(f,0,sizeof(f));
        for(int i=2;i<=n;i++)
            for(int j=2;j<m;j++)
                if(int temp=check(i,j,k))
                    color(i,j,temp);
        int fl=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(f[i][j]==0&&s[i][j]=='*')
                    fl=0;
        puts(fl?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
//