#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, st=1, q;
    cin>>n;
    while(st*10<=n) st*=10;
    if(n/st<5)
    {
        if(st==1) q=n*(n-1)/2;
        else
        {
            q=(n/st)*(n/st)*(st/2)-n/st;
            int bg=max(0, n%st+1-st/2);
            q+=(n%st+1)*(n/st)+bg;
            if(bg==st/2) q--;
        }
    }
    else
    {
        q=n-(st*5-1);
        if(n==st*10-1) q--;
    }
    cout<<q;
}