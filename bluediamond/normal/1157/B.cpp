#include <bits/stdc++.h>

using namespace std;

int f[15];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        vector <int> v(n);
        vector <int> pot(n);
        string s;
        cin>>s;
        for(int i=0;i<n;i++)
        {
                v[i]=(s[i]-'0');
        }
        for(int i=1;i<=9;i++)
        {
                cin>>f[i];
        }
        for(int i=0;i<n;i++)
        {
                int x=v[i];
                pot[i]=(f[x]>=x);
        }
        for(int i=0;i<n;i++)
        {
                /// strict mai mare
                int x=v[i];
                if(f[x]>x)
                {
                        int last=i;
                        for(int j=i;j<n;j++)
                        {
                                if(pot[j]==0)
                                {
                                        break;
                                }
                                last=j;
                        }
                        for(int j=i;j<=last;j++)
                        {
                                v[j]=f[v[j]];
                        }
                        break;
                }
        }
        for(auto &x : v)
        {
                cout<<x;
        }
        cout<<"\n";
        return 0;
}