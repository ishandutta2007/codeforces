#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;

int solve(int l,int r,char c)
{
    if(l==r) return (s[l]!=c);
    int m=l+(r-l+1)/2-1;
    int a=0;
    for(int i=l;i<=m;i++) a+=(s[i]!=c);
    int b=0;
    for(int i=m+1;i<=r;i++) b+=(s[i]!=c);
    return min(a+solve(m+1,r,c+1),b+solve(l,m,c+1));
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n >> s;
        s="$"+s;
        cout << solve(1,n,'a') << "\n";
    }
    return 0;
}