#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, be=-1e9;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int x, ok=0;
        cin>>x;
        for(int b=0; b<=1000; b++) if(b*b==x) ok=1;
        if(ok==0) be=max(be, x);
    }
    cout<<be;
}