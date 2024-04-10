#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=5000+7;

int n,k;
int v[N];
int dp[N][N],r=0;
int mx[N][N];

int gt(int p)
{
        int id=p;
        while(id-1>=1 && v[p]-v[id-1]<=5)
        {
                id--;
        }
        return id;
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>k;
        for(int i=1;i<=n;i++)
        {
                cin>>v[i];
        }
        sort(v+1,v+n+1);
        for(int i=1;i<=n;i++)
        {
                int lst=gt(i)-1;
                for(int cnt=1;cnt<=k;cnt++)
                {
                        dp[i][cnt]=mx[lst][cnt-1];
                        dp[i][cnt]+=(i-lst);
                        mx[i][cnt]=max(dp[i][cnt],mx[i-1][cnt]);
                        r=max(r,dp[i][cnt]);
                }
        }
        cout<<r<<"\n";
        return 0;
}
/**

**/