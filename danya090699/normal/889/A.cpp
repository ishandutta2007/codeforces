#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=1;
    cin>>n;
    bool us[n+1];
    for(int a=0; a<=n; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(us[x]) an++;
        else us[x]=1;
    }
    cout<<an;
}