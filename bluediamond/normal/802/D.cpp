#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        int t;
        cin>>t;
        while (t--)
        {
                int n=250,avg=0;
                vector<int> a(n);
                for (int i=0;i<n;i++)
                {
                        cin>>a[i];
                        avg+=a[i];
                }
                avg/=n;
                int cnt=0;
                for (auto &x : a)
                {
                        cnt+=(x<avg/2 || x>2*avg);
                }
                if (cnt>=15)
                        cout<<"uniform\n";
                else
                        cout<<"poisson\n";
        }

}