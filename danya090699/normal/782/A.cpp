#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q=0, an=0;
    cin>>n;
    bool us[n];
    for(int a=0; a<n; a++) us[a]=0;
    for(int a=0; a<n*2; a++)
    {
        int x;
        cin>>x;
        x--;
        if(us[x]) q--;
        else
        {
            us[x]=1, q++;
        }
        an=max(an, q);
    }
    cout<<an;
}