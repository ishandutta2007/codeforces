#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, yk=0;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        if(ar[a]<0) ar[a]=-ar[a];
    }
    sort(ar, ar+n);
    long long an=0;
    for(int a=0; a<n; a++)
    {
        while(ar[yk]*2<ar[a]) yk++;
        an+=a-yk;
    }
    cout<<an;
}