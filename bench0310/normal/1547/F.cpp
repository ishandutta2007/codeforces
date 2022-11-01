#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const int N=1000000;
    vector<int> sieve(N+1,0);
    for(int i=0;i<=N;i++) sieve[i]=i;
    for(int i=2;i*i<=N;i++)
    {
        if(sieve[i]!=i) continue;
        for(int j=i*i;j<=N;j+=i) if(sieve[j]==j) sieve[j]=i;
    }
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int g=0;
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            g=gcd(g,a[i]);
        }
        for(int &x:a) x/=g;
        vector<array<int,2>> v;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            while(x>1)
            {
                int p=sieve[x];
                v.push_back({p,i});
                while((x%p)==0) x/=p;
            }
        }
        sort(v.begin(),v.end());
        int l=0;
        int sz=v.size();
        int res=0;
        while(l<sz)
        {
            int r=l;
            while(r+1<sz&&v[r+1][0]==v[l][0]) r++;
            vector<int> e;
            for(int i=l;i<=r;i++)
            {
                e.push_back(v[i][1]);
                e.push_back(n+v[i][1]);
            }
            sort(e.begin(),e.end());
            int cnt=e.size();
            int len=0;
            for(int i=0;i<cnt;i++)
            {
                if(i==0||e[i]==e[i-1]+1) len++;
                else
                {
                    res=max(res,len);
                    len=1;
                }
            }
            res=max(res,len);
            l=r+1;
        }
        cout << res << "\n";
    }
    return 0;
}