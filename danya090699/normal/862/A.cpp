#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin>>n>>x;
    bool us[x+1];
    for(int a=0; a<=x; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        int cu;
        cin>>cu;
        if(cu<=x) us[cu]=1;
    }
    int an=0;
    for(int a=0; a<x; a++) if(us[a]==0) an++;
    if(us[x]) an++;
    cout<<an;
}