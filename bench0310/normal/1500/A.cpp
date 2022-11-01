#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n+1,0);
    map<int,int> cnt;
    int good=0;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if((++cnt[a[i]])==4) good=a[i];
    }
    if(good!=0)
    {
        cout << "YES\n";
        int c=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==good)
            {
                cout << i << " \n"[c==3];
                if((++c)==4) break;
            }
        }
        exit(0);
    }
    const int N=5000000;
    vector<array<int,2>> sum[N+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            for(auto [x,y]:sum[a[i]+a[j]])
            {
                if(i!=x&&i!=y&&j!=x&&j!=y)
                {
                    cout << "YES\n";
                    cout << x << " " << y << " " << i << " " << j << "\n";
                    exit(0);
                }
            }
            sum[a[i]+a[j]].push_back({i,j});
        }
    }
    cout << "NO\n";
    return 0;
}