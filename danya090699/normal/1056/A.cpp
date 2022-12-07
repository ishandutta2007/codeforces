#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int q[sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int qq;
        cin>>qq;
        for(int b=0; b<qq; b++)
        {
            int x;
            cin>>x;
            q[x]++;
        }
    }
    for(int a=0; a<sz; a++) if(q[a]==n) cout<<a<<" ";
}