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
                int n,k;
                cin>>n>>k;
                vector<int> a(n);
                for (int i=0;i<n;i++)
                        cin>>a[i];
                if (k==1)
                {
                        bool egale=1;
                        for (int i=1;i<n;i++)
                                if (a[i]!=a[i-1])
                                        egale=0;
                        if (egale==0)
                                cout<<"-1\n";
                        else
                                cout<<"1\n";
                }
                else
                {
                        int nr=0,acum=0,cost=0;
                        for (int i=1;i<n;i++)
                                if (a[i]!=a[i-1])
                                        nr++;
                        if (nr%(k-1)==0&&nr>0)
                                cout<<nr/(k-1)<<"\n";
                        else
                                cout<<nr/(k-1)+1<<"\n";
                }
        }
}