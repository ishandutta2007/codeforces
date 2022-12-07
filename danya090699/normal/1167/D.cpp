#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q0=0, q1=0;
    string s;
    cin>>n>>s;
    for(int a=0; a<n; a++)
    {
        if(s[a]=='(')
        {
            if(q0<q1) cout<<0, q0++;
            else cout<<1, q1++;
        }
        else
        {
            if(q0>q1) cout<<0, q0--;
            else cout<<1, q1--;
        }
    }
}