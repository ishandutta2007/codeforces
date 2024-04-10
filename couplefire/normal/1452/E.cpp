#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,k;
    cin >> n >> m >> k;
    vector<array<int,2>> v(m);
    for(int i=0;i<m;i++) cin >> v[i][0] >> v[i][1];
    sort(v.begin(),v.end(),[](const array<int,2> &a,const array<int,2> &b){return (a[0]+a[1]<b[0]+b[1]);});
    auto solve=[&]()->vector<int> //best score for each prefix
    {
        vector<int> res(m,0);
        vector<int> a(n+1,0);
        for(int i=0;i<m;i++)
        {
            for(int j=v[i][0];j<=v[i][1];j++) a[j]++;
            int now=0;
            for(int j=1;j<=k;j++) now+=a[j];
            res[i]=now;
            for(int j=k+1;j<=n;j++)
            {
                now+=(a[j]-a[j-k]);
                res[i]=max(res[i],now);
            }
        }
        return res;
    };
    vector<int> one=solve();
    reverse(v.begin(),v.end());
    vector<int> two=solve();
    reverse(two.begin(),two.end());
    int res=max(two[0],one[m-1]);
    for(int i=0;i+1<m;i++) res=max(res,one[i]+two[i+1]);
    cout << res << "\n";
    return 0;
}