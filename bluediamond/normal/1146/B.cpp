#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        string t;
        cin>>t;
        int n=t.size();
        string nota;
        for(int j=0;j<n;j++)
        {
                if(t[j]!='a')
                {
                        nota+=t[j];
                }
        }
        int sz=nota.size();
        if(sz%2==0)
        {
                string h1,h2;
                for(int j=0;j<sz/2;j++)
                {
                        h1+=nota[j];
                }
                for(int j=sz/2;j<sz;j++)
                {
                        h2+=nota[j];
                }
                if(h1==h2)
                {
                        for(int j=n-h2.size();j<n;j++)
                        {
                                if(t[j]=='a')
                                {
                                        cout<<":(\n";
                                        return 0;
                                }
                        }
                        for(int j=0;j<n-h2.size();j++)
                        {
                                cout<<t[j];
                        }
                        cout<<"\n";
                        return 0;
                }
        }
        cout<<":(";
        return 0;
}
/**

**/