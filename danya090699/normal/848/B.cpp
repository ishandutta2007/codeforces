//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10, sz2=1e5+10;
vector <pair <int, int> > sp[sz];
queue <int> qu[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, w, h;
    cin>>n>>w>>h;
    int an[n][2];
    vector <pair <int, pair <int, int> > > ar;
    for(int a=0; a<n; a++)
    {

        int ty, p, t;
        cin>>ty>>p>>t;
        if(ty==2) sp[p-t+sz2].push_back(make_pair(p, a));
        else ar.push_back(make_pair(p, make_pair(t, a)));
    }
    sort(ar.begin(), ar.end());
    for(int a=0; a<sz; a++)
    {
        if(sp[a].size()>0)
        {
            sort(sp[a].begin(), sp[a].end());
            for(int b=sp[a].size()-1; b>=0; b--) qu[a].push(sp[a][b].second);
        }
    }
    for(int a=0; a<ar.size(); a++)
    {
        int x=ar[a].first-ar[a].second.first+sz2, nu=ar[a].second.second;
        if(qu[x].size()==0)
        {
            an[nu][0]=ar[a].first;
            an[nu][1]=h;
        }
        else
        {
            qu[x].push(nu);
            int nu2=qu[x].front();
            an[nu2][0]=ar[a].first;
            an[nu2][1]=h;
            qu[x].pop();
        }
    }
    for(int a=0; a<sz; a++)
    {
        if(sp[a].size()>0)
        {
            for(int b=sp[a].size()-1; b>=0; b--)
            {
                int nu=qu[a].front();
                an[nu][0]=w;
                an[nu][1]=sp[a][b].first;
                qu[a].pop();
            }
        }
    }
    for(int a=0; a<n; a++) cout<<an[a][0]<<" "<<an[a][1]<<"\n";
}