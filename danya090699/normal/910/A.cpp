#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, d, an=0;
    cin>>n>>d;
    vector <int> ve;
    for(int a=0; a<n; a++)
    {
        char x;
        cin>>x;
        if(x=='1') ve.push_back(a);
    }
    int yk=0;
    while(yk<ve.size())
    {
        an++;
        int st=yk;
        while(yk<ve.size())
        {
            if(ve[st]+d>=ve[yk]) yk++;
            else break;
        }
        if(yk==ve.size()) break;
        yk--;
        if(yk==st)
        {
            an=-1;
            break;
        }
    }
    cout<<an;
}