#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, an=0, ar[5]={100, 20, 10, 5, 1};
    cin>>n;
    for(int a=0; a<5; a++)
    {
        an+=n/ar[a], n=n%ar[a];
    }
    cout<<an;
}