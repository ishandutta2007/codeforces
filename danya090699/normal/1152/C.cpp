#include <bits/stdc++.h>
using namespace std;
long long be=2e18, bk;
void f(int a, int b, int x)
{
    int add=x-a%x;
    if(add==x) add=0;
    a+=add, b+=add;
    if(1ll*a*b/x<be or (1ll*a*b/x==be and add<bk)) be=1ll*a*b/x, bk=add;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int a, b;
    cin>>a>>b;
    int d=abs(a-b);
    if(d==0) bk=0;
    for(int i=1; i*i<=d; i++)
    {
        if(d%i==0)
        {
            f(a, b, i);
            f(a, b, d/i);
        }
    }
    cout<<bk;
}