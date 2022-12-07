#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> sp[2];
        int su[2]={0, 0}, q0=0;
        for(int a=0; a<n; a++)
        {
            int x;
            cin>>x;
            if(x>0) sp[0].push_back(x), su[0]+=x;
            if(x<0) sp[1].push_back(x), su[1]-=x;
            if(x==0) q0++;
        }
        if(su[0]==su[1]) cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            int i=(su[0]>su[1]) ? 0 : 1;
            for(int j=0; j<2; j++)
            {
                for(int a=0; a<sp[i].size(); a++) cout<<sp[i][a]<<" ";
                i^=1;
            }
            for(int a=0; a<q0; a++) cout<<"0 ";
            cout<<"\n";
        }
    }
}