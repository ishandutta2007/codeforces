#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    bool us[m], ok=1;
    set <string> se;
    for(int a=0; a<m; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        se.insert(s);
    }
    for(auto it=se.begin(); it!=se.end(); it++)
    {
        string s=(*it);
        for(int a=0; a<m; a++)
        {
            if(s[a]=='#')
            {
                if(us[a]) ok=0;
                else us[a]=1;
            }
        }
    }
    if(ok) cout<<"Yes";
    else cout<<"No";
}