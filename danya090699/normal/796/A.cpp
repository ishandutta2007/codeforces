#include <bits/stdc++.h>
using namespace std;
int mo(int x)
{
    if(x<0) return -x;
    else return x;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, k, an=1e9;
    cin>>n>>m>>k;
    m--;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(x!=0 and x<=k) an=min(an, 10*mo(a-m));
    }
    cout<<an;
}