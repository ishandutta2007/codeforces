#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set<int> all;
        for(int i=1;i<=n;i++) all.insert(i);
        vector<int> ans;
        bool ok=1;
        for(int i=0,tmp;i<n;i++) 
        {
            cin>>tmp;
            if(!ok) continue;
            auto cur=all.lower_bound(tmp);
           // cout<<*cur<<endl;
            if(cur==all.begin()&&(*cur)!=tmp)
            {
                ok=0;continue;
            }
            if(cur==all.end()||(*cur)!=tmp) cur--;
            ans.push_back(*cur);
            all.erase(cur);
        }
        if(!ok) cout<<"-1\n";
        else {
            for(auto u:ans) cout<<u<<" ";
            cout<<'\n';
        }
    }
}