#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), q=0;
    for(int a=0; a<n; a++) if(s[a]!=s[n-1-a]) q++;
    if(q==2) cout<<"YES";
    else
    {
        if(n%2==1 and q==0) cout<<"YES";
        else cout<<"NO";
    }
}