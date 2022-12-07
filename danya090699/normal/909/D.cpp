#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    vector <pair <char, int> > ve;
    for(int a=0; a<s.size(); a++)
    {
        if(ve.size())
        {
            if(ve.back().first==s[a]) ve.back().second++;
            else ve.push_back(make_pair(s[a], 1));
        }
        else ve.push_back(make_pair(s[a], 1));
    }
    int an=0;
    while(ve.size()>1)
    {
        vector <pair <char, int> > ve2;
        for(int a=0; a<ve.size(); a++)
        {
            int q=ve[a].second-1;
            if(a!=0 and a!=ve.size()-1) q--;
            char sy=ve[a].first;
            if(q>0)
            {
                if(ve2.size())
                {
                    if(ve2.back().first==sy) ve2.back().second+=q;
                    else ve2.push_back(make_pair(sy, q));
                }
                else ve2.push_back(make_pair(sy, q));
            }
        }
        ve.clear();
        ve.insert(ve.begin(), ve2.begin(), ve2.end());
        an++;
    }
    cout<<an;
}