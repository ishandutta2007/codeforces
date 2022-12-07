#include <bits/stdc++.h>
using namespace std;
int de(int a, int b)
{
    int re=a/b;
    if(a%b>0) re++;
    return re;
}
int main()
{
    int n, an=2e9;
    cin>>n;
    for(int a=1; a<=n; a++) an=min(an, a*2+de(n, a)*2);
    cout<<an;
}