//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    vector <pair <int, int> > po;
    for(int a=0; a<n; a++)
    {
        int l, r;
        cin>>l>>r;
        po.push_back(make_pair(l, 0));
        po.push_back(make_pair(r, 1));
    }
    sort(po.begin(), po.end());
    int q=0, ok=1;
    for(int a=0; a<po.size(); a++)
    {
        if(po[a].second==0) q++;
        else q--;
        if(q>2)
        {
            ok=0;
            break;
        }
    }
    if(ok) cout<<"YES";
    else cout<<"NO";
}