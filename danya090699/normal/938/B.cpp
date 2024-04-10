#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, v1=1, v2=1e6, an=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        an=max(an, min(x-v1, v2-x));
    }
    cout<<an;
}