#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int res=a/b;
    if(a%b!=0) res++;
    return res;
}
int main()
{
    int n, x, an1, an2;
    cin>>n>>x;
    if(n%3==1) an1=1;
    else
    {
        if(de(n, 3)%2==1) an1=2;
        else an1=0;
    }
    if(n%3==0) an2=1;
    else
    {
        if(de(n, 3)%2==1) an2=0;
        else an2=2;
    }
    if(x==an1) cout<<0;
    else if(x==an2) cout<<1;
    else cout<<2;
}