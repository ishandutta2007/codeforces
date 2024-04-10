#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n+1,0);
        for(int i=1;i<=n;i++) cin >> a[i];
        vector<int> b(n+1,0);
        for(int i=1;i<=n;i++) cin >> b[i];
        vector<int> one(n+1,0);
        for(int i=1;i<=n-1;i++) one[i]=one[i-1]+(a[i]<=b[i+1]);
        auto sone=[&](int l,int r)->bool{return (one[r]-one[l-1]==r-l+1);};
        for(int i=1;i<=n;i++)
        {
            int l=0,r=i;
            while(l<r-1)
            {
                int m=(l+r)/2;
                if(a[i]<=b[m]&&sone(m,i-1)) r=m;
                else l=m;
            }
            cout << b[r]-a[i] << " \n"[i==n];
        }
        int p=n+1;
        vector<int> mx(n+1,0);
        for(int i=n;i>=1;i--)
        {
            mx[i]=b[p-1]-a[i];
            if(i>1&&a[i]>b[i-1]) p=i;
        }
        for(int i=1;i<=n;i++) cout << mx[i] << " \n"[i==n];
    }
    return 0;
}