#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000000;
    vector<bool> prime(N+1,1);
    prime[1]=0;
    for(int i=2;i*i<=N;i++)
    {
        if(!prime[i]) continue;
        for(int j=i*i;j<=N;j+=i) prime[j]=0;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n,e;
        cin >> n >> e;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            if(a[i]>1) a[i]=(3-prime[a[i]]);
        }
        ll res=0;
        for(int i=n;i>n-e;i--)
        {
            int nxt_bad=i+e;
            int one=i+e;
            int two=i+e;
            for(int j=i;j>=1;j-=e)
            {
                if(a[j]==2)
                {
                    two=one;
                    one=j;
                }
                else if(a[j]==3) nxt_bad=j;
                int l=max(j+e,one);
                int r=min(two,nxt_bad);
                res+=max(0,(r-l)/e);
            }
        }
        cout << res << "\n";
    }
    return 0;
}