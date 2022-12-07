#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, ma=0, an=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ma=max(ma, ar[a]);
    }
    int yk=0;
    while(yk<n)
    {
        int st=yk;
        while(yk<n)
        {
            if(ar[yk]==ar[st]) yk++;
            else break;
        }
        if(ar[st]==ma) an=max(an, yk-st);
    }
    cout<<an;
}