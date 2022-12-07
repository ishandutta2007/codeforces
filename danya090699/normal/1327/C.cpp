#include <bits/stdc++.h>
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    string s;
    for(int a=0; a<n-1; a++) s.push_back('D');
    for(int a=0; a<m-1; a++) s.push_back('L');
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<n-1; b++)
        {
            if(a&1) s.push_back('D');
            else s.push_back('U');
        }
        if(a+1<m) s.push_back('R');
    }
    cout<<s.size()<<"\n"<<s;
}