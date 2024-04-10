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
int ans[10005];
int query(int x,int y,int t){
    if(t==0) printf("or %d %d\n",x,y);
    else printf("and %d %d\n",x,y);
    fflush(stdout);
    int temp;
    scanf("%d",&temp);
    return temp;
}
int f[10005][31],a[10005],temp[10005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            int nxt=i+1;
            if(nxt>n) nxt-=n;
            int o=query(i,nxt,0),a=query(i,nxt,1);
            for(int j=30;j>=0;j--){
                if(!((1<<j)&o)) f[i][j]=0;
                else if((1<<j)&a) f[i][j]=2;
                else f[i][j]=1;
            }
        }
        for(int i=30;i>=0;i--){
            //for(int j=1;j<=n;j++) cout<<a[j]<<" ";puts("");
            //for(int j=1;j<=n;j++) cout<<f[j][i]<<" ";puts("");
            temp[1]=0;
            for(int j=1;j<=n;j++) temp[j+1]=f[j][i]-temp[j];
            //for(int j=1;j<=n+1;j++) cout<<temp[j]<<" ";puts("");
            int fl=1;
            for(int j=1;j<=n;j++) if(temp[j]>1||temp[j]<0) fl=0;
            if(temp[1]!=temp[n+1]) fl=0;
            if(fl){
                for(int j=1;j<=n;j++) a[j]+=(1<<i)*temp[j];
                continue;
            }
            temp[1]=1,fl=1;
            for(int j=1;j<=n;j++) temp[j+1]=f[j][i]-temp[j];
            for(int j=1;j<=n;j++) if(temp[j]>1||temp[j]<0) fl=0;
            if(temp[1]!=temp[n+1]) fl=0;
            for(int j=1;j<=n;j++) a[j]+=(1<<i)*temp[j];
            assert(fl);
        }
        sort(a+1,a+n+1);
        printf("finish %d\n",a[k]);
        //for(int i=1;i<=n;i++) cout<<a[i]<<endl;
    }
    return 0;
}
//
/// 
//01
//