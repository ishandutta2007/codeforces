//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0, qq;
    cin>>n;
    int ne[n];
    bool us[n];
    for(int a=0; a<n; a++)
    {
        cin>>ne[a];
        ne[a]--;
        us[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        if(us[a]==0)
        {
            int cu=a;
            while(us[cu]==0)
            {
                us[cu]=1, cu=ne[cu];
            }
            q++;
        }
    }
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        qq+=x;
    }
    int an=1-qq%2;
    if(q>1) an+=q;
    cout<<an;
}