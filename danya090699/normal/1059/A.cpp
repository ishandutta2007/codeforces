#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, l, x, pr=0, an=0;
    cin>>n>>l>>x;
    for(int a=0; a<n; a++)
    {
        int t, q;
        scanf("%d%d", &t, &q);
        an+=(t-pr)/x;
        pr=t+q;
    }
    an+=(l-pr)/x;
    cout<<an;
}