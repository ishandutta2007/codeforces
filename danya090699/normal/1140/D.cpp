#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, an=0;
    cin>>n;
    for(int a=2; a+1<=n; a++) an+=a*(a+1);
    cout<<an;
}