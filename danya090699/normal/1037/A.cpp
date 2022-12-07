#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, an=0;
    cin>>n;
    while(n)
    {
        n/=2, an++;
    }
    cout<<an;
}