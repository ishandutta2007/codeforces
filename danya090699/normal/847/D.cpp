#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, t, an=0, q=0;
    cin>>n>>t;
    vector <pair <int, int> > sp;
    for(int a=1; a<=n; a++)
    {
        int x;
        cin>>x;
        int l=max(0, x-a), r=(t-1)-a;
        if(r>=l)
        {
            sp.push_back(make_pair(l, 0));
            sp.push_back(make_pair(r, 1));
        }
    }
    sort(sp.begin(), sp.end());
    for(int a=0; a<sp.size(); a++)
    {
        if(sp[a].second==0) q++;
        else q--;
        an=max(an, q);
    }
    cout<<an;
}