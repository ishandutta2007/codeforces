#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    int q=n/4+1;
    for(int a=0; a<q; a++)
    {
        if(a+1==q) cout<<5;
        else cout<<4;
    }
    cout<<"\n";
    for(int a=0; a<q; a++) cout<<5;
}