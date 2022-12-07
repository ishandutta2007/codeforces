#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0;
    cin>>n;
    int pri[n], to[n], us[n];
    for(int a=0; a<n; a++) cin>>pri[a];
    for(int a=0; a<n; a++)
    {
        cin>>to[a], to[a]--, us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            vector <int> sp;
            int cu=a;
            while(us[cu]==0)
            {
                us[cu]=1, sp.push_back(cu), cu=to[cu];
            }
            if(us[cu]==1)
            {
                int be=1e9;
                while(us[cu]==1)
                {
                    us[cu]=2, be=min(be, pri[cu]), cu=to[cu];
                }
                an+=be;
            }
            for(int b=0; b<sp.size(); b++) us[sp[b]]=2;
        }
    }
    cout<<an;
}