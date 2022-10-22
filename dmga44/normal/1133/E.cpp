#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 5005

int a[MAXN],dp[MAXN][MAXN],mi[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cout.tie();

    int n,k,l=0,r=0;
    cin >> n >> k;
    for(int i=0;i<n;i++)
        cin >> a[i];

    sort(a,a+n);
//    for(int i=0;i<n;i++)
//        db(a[i])

    while(l<n && r<n)
    {
        while(r<n && a[r]<=a[l]+5)
        {
            mi[r]=l;
//            db(a[r])
//            db(a[l])
            r++;
        }
        while(r<n && l<n && a[l]<a[r]-5)
            l++;
    }

    for(int i=0;i<n;i++)
        dp[0][i]=0;
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!mi[j])
                dp[i][j]=j+1;
            else
                dp[i][j]=(j-mi[j]+1)+dp[i-1][mi[j]-1];
            if(j)
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
        }
    }
//    for(int i=0;i<n;i++)
//        cout << mi[i] << ' ';
//    cout << '\n';

    int res=dp[k][n-1];
    db(res)

    return 0;
}