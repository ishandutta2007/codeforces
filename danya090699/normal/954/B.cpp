#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an;
    string s;
    cin>>n>>s;
    an=n;
    for(int a=1; a*2<=n; a++) if(s.substr(0, a)==s.substr(a, a)) an=a+1+(n-2*a);
    cout<<an;
}