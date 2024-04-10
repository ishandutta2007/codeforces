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
    int n, t, k, d;
    cin>>n>>t>>k>>d;
    int q=de(n, k);
    if(q-d/t>1) cout<<"YES";
    else cout<<"NO";
}