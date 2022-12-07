#include <bits/stdc++.h>
using namespace std;
int q[1<<20][2];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, cu=0;
    cin>>n;
    long long an=0;
    for(int a=0; a<n; a++)
    {
        int x;
        scanf("%d", &x);
        q[cu][a%2]++;
        cu^=x;
        an+=q[cu][(a+1)%2];
    }
    cout<<an;
}