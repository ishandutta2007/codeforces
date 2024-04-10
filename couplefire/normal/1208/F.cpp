#include<bits/stdc++.h>
using namespace std;
int n ;
int a[1000005];
int c[2097153];
inline int lowbit(int x)
{
    return x & (-x);
}
int vis[2097153] ;
int t ;
void add(int x)
{
    if(c[x] == 2 || vis[x] == t) return ;
    c[x]++;vis[x] = t;
    int d = x;
    while(d) {
        add(x - lowbit(d)) ;
        d -= lowbit(d);
    }
    return ;
}
int main()
{
    scanf("%d",&n) ;
    for(int i = 1;i <= n;i++) scanf("%d",&a[i]) ;
    int ans = 0;
    for(int i = n;i >= 1;i--) {
        int r = 0;t = i;
        for(int j = 20 ; j >= 0;j--) {
            r += (1<<j) ;
            if(c[(r ^ a[i]) & r] != 2) r -= (1<<j);
        }
        ans = max(ans , r);
        add(a[i]);
    }
    cout << ans ;
    return 0;
}