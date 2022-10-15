#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100000+5;
map<string, vector<int> >mp;
map<string,int>lst;
vector< pair<int,int> >mij;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vector<string>who;
    string str[N];
    int n,len;
    cin>>n>>len;
    for(int i=1;i<=n;i++)
    {
        int sc;
        cin>>str[i]>>sc;
        who.push_back(str[i]);
        mp[str[i]].push_back(sc);
        string inv=str[i];
        reverse(inv.begin(),inv.end());
      ///  if(inv==str[i]) mij.push_back(make_pair(sc,0));
    }
    sort(who.begin(),who.end());
    sort(mp[who[0]].begin(),mp[who[0]].end());
    for(int i=1;i<n;i++)
        if(who[i]!=who[i-1])
            sort(mp[who[i]].begin(),mp[who[i]].end());
    int ans1=0;
    int add=0;
    for(int i=1;i<=n;i++)
    {
        string cur=str[i];
        string inv=cur;
        reverse(inv.begin(),inv.end());
        if(mp[cur].empty() || mp[inv].empty()) continue;
        if(cur!=inv)
        {
            int a=mp[cur].back();
            int b=mp[inv].back();
            if(a+b>0)
            {
                ans1+=a+b;
                mp[cur].pop_back();
                mp[inv].pop_back();
            }
            continue;
        }
        if(cur==inv)
        {
           /// cout<<" = "<<cur<<" "<<inv<<" , "<<mp[cur].size()<<"\n";
            if(mp[cur].size()>=2)
            {
                int a=mp[cur][mp[cur].size()-1];
                int b=mp[cur][mp[cur].size()-2];
                if(a+b>0)
                {
                    ans1+=a+b;
                    mp[cur].pop_back();
                    mp[inv].pop_back();
                    mij.push_back({a,a+b});
                    mij.push_back({b,a+b});
                }
            }
        }
    }
    for(auto itr:mp)
    {
        string inv=itr.first;
        reverse(inv.begin(),inv.end());
        if(itr.first==inv)
        {
            int sz=itr.second.size();
            if(sz>=1)
            {
                mij.push_back({itr.second.back(),0});
            }
        }
    }
    int ans=ans1;
    for(auto itr:mij)
    {
        ans=max(ans,ans1-itr.second+itr.first);
    }
    cout<<ans<<"\n";
    return 0;
}
/**

**/