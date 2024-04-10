#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
int mp[2000100], f[2000100];
 
bool check(int n, int m, int x, int y)
{
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            f[abs(x-i)+abs(y-j)]++;
    for(int i=0;i<1000100;i++)
        if(f[i]!=mp[i]) return false;
    return true;
}
 
int main ()
{
    ios_base::sync_with_stdio(false);
    int t, b=0; cin >> t;
    for(int i=0;i<t;i++) {
        int x; cin >> x;
        mp[x]++;
        b=max(b,x);
    }
    int x;
    for(x=1;x<x+1;x++)
        if(mp[x]<4*x) break;
    for(int n=1;n*n<=t;n++) {
        if(t%n==0) {
            int m=t/n, y=n+m-x-b;
            if(check(n,m,x,y)) { cout << n << " " << m << endl << x << " " << y; return 0; }
            if(check(m,n,x,y)) { cout << m << " " << n << endl << x << " " << y; return 0;}
        }
    }
    cout << -1 << endl;
    return 0;
}