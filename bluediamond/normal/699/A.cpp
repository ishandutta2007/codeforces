#include <bits/stdc++.h>

using namespace std;

int n;
const int nmax=200000;
char s[nmax+5];
int v[nmax+5];
int ans=2e9;
int main()
{
    cin>>n;
    cin.get();
    cin.getline(s,nmax+5);
    for(int i=0;i<n;i++)
        cin>>v[i];
    for(int i=0;i+1<n;i++)
    {
        if(s[i]=='R' and s[i+1]=='L')
            ans=min(ans,(v[i+1]-v[i])/2);
    }
    if(ans==2e9)
        cout<<-1;
    else
        cout<<ans;
    return 0;
}
/**

**/