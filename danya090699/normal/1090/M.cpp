#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    int ar[n], yk=0, pr=0, an=0;
    for(int a=0; a<n; a++) scanf("%d", &ar[a]);
    while(yk<n)
    {
        int st=yk;
        while(yk<n)
        {
            if(ar[yk]==ar[st]) yk++;
            else break;
        }
        if(yk-st>1)
        {
            an=max(an, st+1-pr), pr=yk-1;
        }
    }
    an=max(an, n-pr);
    cout<<an;
}