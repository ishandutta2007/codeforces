//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0;
    cin>>n;
    pair <int, int> ar[n];
    bool us[n];
    for(int a=0; a<n; a++)
    {
        cin>>ar[a].first;
        ar[a].second=a;
        us[a]=0;
    }
    sort(ar, ar+n);
    vector <int> an[n];
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            int cu=a;
            while(us[cu]==0)
            {
                us[cu]=1;
                an[q].push_back(cu);
                cu=ar[cu].second;
            }
            q++;
        }
    }
    cout<<q<<"\n";
    for(int a=0; a<q; a++)
    {
        cout<<an[a].size();
        for(int b=0; b<an[a].size(); b++) printf(" %d", an[a][b]+1);
        cout<<"\n";
    }
}