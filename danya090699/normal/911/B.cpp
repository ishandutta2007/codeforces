#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a, b;
    cin>>n>>a>>b;
    for(int i=min(a, b); ; i--)
    {
        if(a/i+b/i>=n)
        {
            cout<<i;
            break;
        }
    }
}