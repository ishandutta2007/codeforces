#pragma GCC optimize("Ofast,unroll-loops")
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[1005][1005];
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int ans = 0, n;
        cin >> n;
        for (int i = 1,x; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                scanf("%d",&a[i][j]);
            }
        }
        for(int i=1,pre=0;i<n-1;i+=2){
            int s=i+1,now=0;
            for(int j=1;j<=n;j+=2){
                int k=s-j;
                if(k<=0||k>n||j<=0||j>n) continue;
                now^=a[k][j];
            }
            ans^=now^pre;
            pre=now^pre;
        }
        for(int i=n,pre=0;i>=1;i-=2){
            int s=i+n,now=0;
            for(int j=n;j>=1;j-=2){
                int k=s-j;
                if(k<=0||k>n||j<=0||j>n) continue;
                now^=a[k][j];
            }
            ans^=now^pre;
            pre=now^pre;
        }
        for(int i=1;i<=n;i++) for(int j=1;j<=n/2;j++) swap(a[i][j],a[i][n-j+1]);
        for(int i=1,pre=0;i<n-1;i+=2){
            int s=i+1,now=0;
            for(int j=1;j<=n;j+=2){
                int k=s-j;
                if(k<=0||k>n||j<=0||j>n) continue;
                now^=a[k][j];
            }
            ans^=now^pre;
            pre=now^pre;
        }
        for(int i=n,pre=0;i>=1;i-=2){
            int s=i+n,now=0;
            for(int j=n;j>=1;j-=2){
                int k=s-j;
                if(k<=0||k>n||j<=0||j>n) continue;
                now^=a[k][j];
            }
            ans^=now^pre;
            pre=now^pre;
        }
        printf("%d\n",ans);
    }
    return 0;
}
//unordered_map
//cf