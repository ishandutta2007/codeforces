#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        if(a%4<2) cout<<"a";
        else cout<<"b";
    }
}