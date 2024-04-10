#include <bits/stdc++.h>
using namespace std;
const int sz=110;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int an[sz];
    an[1]=1, an[2]=2;
    for(int a=3; a<=n; a++) an[a]=a+an[a-2];
    cout<<an[n];
}