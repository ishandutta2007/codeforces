#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int re=a/b;
    if(a%b!=0) re++;
    return re;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, cu=1;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        int s, d;
        cin>>s>>d;
        cu=max(cu, s);
        cu=s+de(cu-s, d)*d;
        cu++;
    }
    cout<<cu-1;
}