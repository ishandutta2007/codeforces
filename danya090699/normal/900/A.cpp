#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q1=0, q2=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, y;
        cin>>x>>y;
        if(x<0) q1++;
        else q2++;
    }
    if(q1<2 or q2<2) cout<<"Yes";
    else cout<<"No";
}