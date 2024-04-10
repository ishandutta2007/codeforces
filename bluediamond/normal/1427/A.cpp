#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
        ios::sync_with_stdio(0); cin.tie(0);
        int t;
        cin>>t;
        while (t--)
        {
                int n;
                cin>>n;
                vector<int> a(n);
                for (int i=0;i<n;i++)
                        cin>>a[i];
                sort(a.begin(),a.end());
                ll s=0;
                for (int i=0;i<n;i++)
                        s+=a[i];
                if (s==0)
                {
                        cout<<"NO\n";
                        continue;
                }
                s=0;
                for (int i=0;i<n;i++)
                        s+=abs(a[i]);
                cout<<"YES\n";
                ll pl=0;
                for (int i=0;i<n;i++)
                        if (a[i]>0)
                                pl+=a[i];
                if (pl>s-pl)
                {
                        for (int i=0;i<n;i++)
                                if (a[i]>0)
                                        cout<<a[i]<<" ";
                        for (int i=0;i<n;i++)
                                if (a[i]<=0)
                                        cout<<a[i]<<" ";
                        cout<<"\n";
                }
                else
                {
                        for (int i=0;i<n;i++)
                                if (a[i]<0)
                                        cout<<a[i]<<" ";
                        for (int i=0;i<n;i++)
                                if (a[i]>=0)
                                        cout<<a[i]<<" ";
                        cout<<"\n";
                }
        }
}