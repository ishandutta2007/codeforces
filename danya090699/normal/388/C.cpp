//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, p1=0, p2=0;
    cin>>n;
    vector <int> ve;
    for(int a=0; a<n; a++)
    {
        int q;
        cin>>q;
        for(int a=0; a<q/2; a++)
        {
            int x;
            cin>>x;
            p1+=x;
        }
        if(q%2==1)
        {
            int x;
            cin>>x;
            ve.push_back(x);
        }
        for(int a=0; a<q/2; a++)
        {
            int x;
            cin>>x;
            p2+=x;
        }
    }
    sort(ve.begin(), ve.end(), greater <int>());
    for(int a=0; a<ve.size(); a++)
    {
        if(a%2==0) p1+=ve[a];
        else p2+=ve[a];
    }
    cout<<p1<<" "<<p2;
}