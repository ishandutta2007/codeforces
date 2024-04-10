#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, be=0, bnu;
    string s[3];
    cin>>n>>s[0]>>s[1]>>s[2];
    int m=s[0].size();
    pair <int, int> an[3];
    for(int a=0; a<3; a++)
    {
        map <char, int> ma;
        for(int b=0; b<m; b++) ma[s[a][b]]++;
        vector <int> sp;
        for(auto it=ma.begin(); it!=ma.end(); it++) sp.push_back((*it).second);
        sort(sp.begin(), sp.end(), greater <int>());
        if(sp.size()>1) an[a].first=sp[0]+min(n, m-sp[0]);
        else
        {
            if(m==1) an[a].first=m;
            else
            {
                if(n==1) an[a].first=m-1;
                else an[a].first=m;
            }
        }
        an[a].second=a;
    }
    sort(an, an+3, greater <pair <int, int> >());
    if(an[0].first==an[1].first) cout<<"Draw";
    else
    {
        if(an[0].second==0) cout<<"Kuro";
        if(an[0].second==1) cout<<"Shiro";
        if(an[0].second==2) cout<<"Katie";
    }
}