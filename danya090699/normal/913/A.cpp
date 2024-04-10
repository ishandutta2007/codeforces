#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, st=1;
    cin>>n>>m;
    for(int a=1; a<=n; a++)
    {
        if(st>m) break;
        st*=2;
    }
    cout<<m%st;
}