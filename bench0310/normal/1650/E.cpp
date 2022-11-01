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
        int n,d;
        cin >> n >> d;
        vector<int> a(n+1,0);
        multiset<int> s;
        for(int i=1;i<=n;i++)
        {
            cin >> a[i];
            s.insert(a[i]-a[i-1]-1);
        }
        int res=0;
        for(int i=1;i<n;i++)
        {
            s.erase(s.find(a[i]-a[i-1]-1));
            s.erase(s.find(a[i+1]-a[i]-1));
            s.insert(a[i+1]-a[i-1]-1);
            int tmp=(*s.rbegin());
            res=max(res,min(*s.begin(),(tmp-1)/2));
            res=max(res,min(*s.begin(),d-a[n]-1));
            s.erase(s.find(a[i+1]-a[i-1]-1));
            s.insert(a[i]-a[i-1]-1);
            s.insert(a[i+1]-a[i]-1);
        }
        s.erase(s.find(a[n]-a[n-1]-1));
        res=max(res,min(*s.begin(),d-a[n-1]-1));
        cout << res << "\n";
    }
    return 0;
}