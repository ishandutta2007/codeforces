#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k, cu=0;
    cin>>n>>k;
    int m=(1<<k)-1;
    long long an=(1ll*(n+1)*n)/2;
    map <int, int> ma;
    ma[0]++;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        cu^=x;
        if(ma[cu]<ma[cu^m]) an-=ma[cu];
        else
        {
            cu^=m, an-=ma[cu];
        }
        ma[cu]++;
    }
    cout<<an;
}