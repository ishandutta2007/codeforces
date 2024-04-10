#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, prx=0, pry=0, an=1;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, y;
        cin>>x>>y;
        int l=max(prx, pry), r=min(x, y);
        if(l<=r) an+=r-l+1;
        if(prx==pry) an--;
        prx=x, pry=y;
    }
    cout<<an;
}