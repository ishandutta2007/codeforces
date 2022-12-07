#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, an=1e9;
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        if(k%x==0) an=min(an, k/x);
    }
    cout<<an;
}