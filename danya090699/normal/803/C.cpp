#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    int n, k, inf=1e6;
    cin>>n>>k;
    if(k>inf) cout<<-1;
    else
    {
        vector <int> de;
        int q=(1+k)*k/2, fo=0;
        for(int a=1; a*a<=n; a++)
        {
            if(n%a==0)
            {
                de.push_back(a), de.push_back(n/a);
            }
        }
        sort(de.begin(), de.end());
        for(int a=de.size()-1; a>=0; a--)
        {
            if(n/de[a]>=q)
            {
                for(int b=1; b<k; b++) cout<<b*de[a]<<" ";
                cout<<(k+n/de[a]-q)*de[a];
                fo=1;
                break;
            }
        }
        if(fo==0) cout<<-1;
    }
}