#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    long long an=0;
    int pr=2e9;
    for(int a=n-1; a>=0; a--)
    {
        int cu=min(pr-1, ar[a]);
        if(cu<0) cu=0;
        an+=cu, pr=cu;
    }
    cout<<an;
}