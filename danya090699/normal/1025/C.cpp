#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    cin>>s;
    int n=s.size(), an=1, cu=1;
    s+=s;
    char pr=s[0];
    for(int a=1; a<s.size(); a++)
    {
        if(s[a]!=pr) cu++;
        else cu=1;
        an=max(an, cu);
        pr=s[a];
    }
    cout<<min(an, n);
}