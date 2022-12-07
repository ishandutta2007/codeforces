#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1e9;
    string s;
    cin>>n>>s;
    char ar[4]={'A', 'C', 'T', 'G'};
    for(int a=0; a+4<=n; a++)
    {
        int cu=0;
        for(int b=a; b<a+4; b++)
        {
            int x=(s[b]-ar[b-a]), y=(ar[b-a]-s[b]);
            if(x<0) x+=26;
            if(y<0) y+=26;
            cu+=min(x, y);
        }
        an=min(an, cu);
    }
    cout<<an;
}