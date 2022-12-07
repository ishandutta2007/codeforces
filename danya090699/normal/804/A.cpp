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
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    cout<<de(n, 2)-1;
}