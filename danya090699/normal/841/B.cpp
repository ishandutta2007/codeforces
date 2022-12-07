//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, su=0, fo=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        su=(su+x)%2;
        if(x%2) fo=1;
    }
    if(su) cout<<"First";
    else
    {
        if(fo) cout<<"First";
        else cout<<"Second";
    }
}