#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int n;
        cin>>n;
        set<int>s;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                s.insert(x);
        }
        vector<int>v;
        for(auto &x:s)
        {
                v.push_back(x);
        }
        if(v.size()==1)
        {
                cout<<"0\n";
                return 0;
        }
        if(v.size()==2)
        {
                if((v[1]-v[0])%2==0)
                {
                        cout<<(v[1]-v[0])/2<<"\n";
                }
                else
                {
                        cout<<(v[1]-v[0])<<"\n";
                }
                return 0;
        }
        if(v.size()==3)
        {
                if(v[2]-v[1]==v[1]-v[0])
                {
                        cout<<v[1]-v[0]<<"\n";
                        return 0;
                }
        }
        cout<<"-1\n";
        return 0;
}
/**

**/