#include <bits/stdc++.h>
#define int long long
using namespace std;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int ar[n];
    for(int a=0; a<n; a++) scanf("%lld", &ar[a]);
    if(n==1)
    {
        cout<<"1 1\n"<<-ar[0]<<"\n";
        cout<<"1 1\n0\n";
        cout<<"1 1\n0";
    }
    else
    {
        cout<<1<<" "<<n<<"\n";
        for(int a=0; a<n; a++)
        {
            int os;
            if(ar[a]>=0) os=ar[a]%(n-1);
            else os=(n-1-abs(ar[a])%(n-1))%(n-1);

            ar[a]+=(n-1-os)*n;
            printf("%lld ", (n-1-os)*n);
        }
        cout<<"\n"<<1<<" "<<n-1<<"\n";
        for(int a=0; a<n-1; a++)
        {
            printf("%lld ", -ar[a]);
        }
        cout<<"\n"<<n<<" "<<n<<"\n"<<-ar[n-1];
    }
}