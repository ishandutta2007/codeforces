#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x=0, y=0, q=0;
    cin>>n;
    vector <int> sp;
    for(int a=0; a<n; a++)
    {
        char sy;
        cin>>sy;
        if(sy=='U') y++;
        else x++;
        if(y>x) sp.push_back(0);
        if(y<x) sp.push_back(1);
    }
    for(int a=0; a+1<sp.size(); a++) if(sp[a]!=sp[a+1]) q++;
    cout<<q;
}