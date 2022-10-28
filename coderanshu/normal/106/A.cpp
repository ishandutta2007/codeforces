#include<bits/stdc++.h>
using namespace std;
bool comp(char a ,char b)
{
    if(a=='T')a='A';
    else if(a=='K')a='X';
    else if(a=='A')a='Z';
    if(b=='T')b='A';
    else if(b=='K')b='X';
    else if(b=='A')b='Z';
    return a>b;    
}
int main()
{
    ios_base::sync_with_stdio(0);
    char t,a[3],b[3];
    cin>>t>>a>>b;
    if(a[1]!=b[1] && a[1]!=t)
    {
        cout<<"NO";return 0;
    }
    else if(a[1]==b[1])
    {
        if(comp(a[0],b[0]))cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"YES";
    return 0;
}