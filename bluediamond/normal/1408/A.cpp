#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        
        while (t--)
        {
                int n;
                cin>>n;
                vector<int> a(n),b(n),c(n);
                for (int i=0;i<n;i++) cin>>a[i];
                for (int i=0;i<n;i++) cin>>b[i];
                for (int i=0;i<n;i++) cin>>c[i];
                vector<int> rez(n);
                rez[0]=a[0];
                for (int i=1;i<n-1;i++)
                {
                        if (a[i]!=rez[i-1])
                                rez[i]=a[i];
                        else
                                rez[i]=b[i];
                }
                if (a[n-1]!=rez[n-2]&&a[n-1]!=rez[0])
                        rez[n-1]=a[n-1];
                if (b[n-1]!=rez[n-2]&&b[n-1]!=rez[0])
                        rez[n-1]=b[n-1];
                if (c[n-1]!=rez[n-2]&&c[n-1]!=rez[0])
                        rez[n-1]=c[n-1];
                for (auto &x:rez)
                        cout<<x<<" ";
                cout<<"\n";
        }
}