#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q=0, fo=0;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        if(x<=q) q=max(q, x+1);
        else
        {
            cout<<a+1;
            fo=1;
            break;
        }
    }
    if(fo==0) cout<<-1;
}