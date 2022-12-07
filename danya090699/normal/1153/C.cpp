#include <bits/stdc++.h>
using namespace std;
void err()
{
    cout<<":(";
    exit(0);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int q=0, cu=0;
    string s;
    cin>>s;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='(') q++;
    }

    for(int a=0; a<n; a++)
    {
        if(s[a]=='?')
        {
            if(q<n/2) s[a]='(', q++;
            else s[a]=')';
        }
        if(s[a]=='(') cu++;
        else cu--;

        if(a+1<n and cu<=0) err();
    }
    if(cu!=0) err();
    cout<<s;
}