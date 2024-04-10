#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    if(s.size()>=4)
    {
        map <char, int> ma;
        for(int a=0; a<s.size(); a++) ma[s[a]]++;
        if(ma.size()==4) cout<<"Yes";
        else if(ma.size()==3) cout<<"Yes";
        else if(ma.size()==2)
        {
            int mi=1e9;
            for(auto it=ma.begin(); it!=ma.end(); it++) mi=min(mi, (*it).second);
            if(mi==1) cout<<"No";
            else cout<<"Yes";
        }
        else cout<<"No";
    }
    else cout<<"No";

}