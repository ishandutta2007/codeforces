//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    int la[26], us[26], q=0, ok=1;
    for(int a=0; a<26; a++)
    {
        la[a]=-1, us[a]=0;
    }
    for(int a=n-1; a>=0; a--) if(la[s[a]-'A']==-1) la[s[a]-'A']=a;
    for(int a=0; a<n; a++)
    {
        int sy=s[a]-'A';
        if(us[sy]==0)
        {
            us[sy]=1, q++;
        }
        if(q>k) ok=0;
        if(la[sy]==a) q--;
    }
    if(ok) cout<<"NO";
    else cout<<"YES";
}