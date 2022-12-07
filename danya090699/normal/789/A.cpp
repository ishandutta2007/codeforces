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
    int n, k, q=0;
    cin>>n>>k;
    for(int a=0; a<n; a++)
    {
        int x;
        cin>>x;
        q+=de(x, k);
    }
    cout<<de(q, 2);
}