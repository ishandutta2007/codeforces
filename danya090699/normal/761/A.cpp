//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b;
    cin>>a>>b;
    if(a==0 and b==0) cout<<"NO";
    else
    {
    if(a-b==1 or b-a==1 or a-b==0 or b-a==0) cout<<"YES";
    else cout<<"NO";
    }
}