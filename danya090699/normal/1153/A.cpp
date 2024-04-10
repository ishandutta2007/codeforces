#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, t, an, be=1e9;
    cin>>n>>t;
    for(int a=0; a<n; a++)
    {
        int s, d, cu;
        cin>>s>>d;
        if(t<=s) cu=s;
        else cu=t+(d-(t-s)%d)%d;
        if(cu<be) an=a+1, be=cu;
    }
    cout<<an;
}