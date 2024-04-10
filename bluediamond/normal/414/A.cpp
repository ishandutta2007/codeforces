#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int) 1e5+7;
int n;
int k;

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin>>n>>k;
        if (n==1)
        {
                if (k==0)
                        cout<<"1\n";
                else
                        cout<<"-1\n";
                return 0;
        }
        if (k<n/2)
        {
                cout<<"-1\n";
                return 0;
        }
        int e=n/2-1;
        int r=k-e;
        cout<<r<<" "<<2*r<<" ";
        for (int i=1;i<=n-2;i++)
                cout<<2*r+i<<" ";
        cout<<"\n";
}