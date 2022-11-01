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
        vector<int> v;
        for(int i=2;i<=n-1;i++) if(a[i-1]<a[i]&&a[i]>a[i+1]) v.push_back(i);
        int res=0;
        int idx=0;
        int sz=v.size();
        while(idx<sz)
        {
            res++;
            if(idx+1<sz&&v[idx+1]-v[idx]==2)
            {
                a[v[idx]+1]=max(a[v[idx]],a[v[idx]+2]);
                idx+=2;
            }
            else
            {
                a[v[idx]]=max(a[v[idx]-1],a[v[idx]+1]);
                idx++;
            }
        }
        cout << res << "\n";
        for(int i=1;i<=n;i++) cout << a[i] << " \n"[i==n];
    }
    return 0;
}