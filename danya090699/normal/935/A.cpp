#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q=0;
    cin>>n;
    for(int a=1; a<n; a++) if((n-a)%a==0) q++;
    cout<<q;
}