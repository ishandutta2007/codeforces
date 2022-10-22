#include <bits/stdc++.h>

using namespace std;
int t, n, k, d, a[105], b[105], ans, Min;
vector <int> v;

int main()
{
    cin >> t;
    for(int test=0;test<t;test++)
    {
        for(int i=0;i<105;i++)
            b[i]=0;
        ans=0;
        cin >> n >> k >> d;
        for(int i=0;i<n;i++)
            cin >> a[i];
        for(int i=0;i<d;i++)
        {
            b[a[i]]++;
            if(b[a[i]]==1)
                ans++;
        }
        Min=ans;
        for(int i=d;i<n;i++)
        {
            b[a[i]]++;
            if(b[a[i]]==1)
                ans++;
            b[a[i-d]]--;
            if(b[a[i-d]]==0)
                ans--;
            Min=min(Min, ans);
        }
       v.push_back(Min);
    }
    for(int i=0;i<t;i++)
        cout << v[i] << "\n";
    return 0;
}