#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int x, y, z, n, an=0;
    cin>>x>>y>>z>>n;
    for(int a=0; a<n; a++)
    {
        int i;
        cin>>i;
        if(i>y and i<z) an++;
    }
    cout<<an;
}