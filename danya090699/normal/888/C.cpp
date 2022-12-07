#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    char x;
    int pr[26], ma[26], b=0;
    for(int a=0; a<26; a++)
    {
        pr[a]=-1, ma[a]=0;
    }
    while(cin>>x)
    {
        int i=x-'a';
        ma[i]=max(ma[i], b-pr[i]);
        pr[i]=b, b++;
    }
    for(int a=0; a<26; a++) ma[a]=max(ma[a], b-pr[a]);
    int an=1e9;
    for(int a=0; a<26; a++) an=min(an, ma[a]);
    cout<<an;
}