#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10;
long long q[sz*2], su[sz*2], an=1e18;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x, y;
    cin>>n>>x>>y;
    for(int a=0; a<sz*2; a++)
    {
        q[a]=0, su[a]=0;
    }
    for(int a=0; a<n; a++)
    {
        int z;
        scanf("%d", &z);
        q[z]++, su[z]+=z;
    }
    for(int a=1; a<sz*2; a++)
    {
        q[a]+=q[a-1], su[a]+=su[a-1];
    }
    for(int a=2; a<sz; a++)
    {
        int c=min(x/y, a-1);
        long long cu=0;
        for(int b=a; b<sz*2; b+=a)
        {
            cu+=x*(q[b-(c+1)]-q[b-a]);
            int qq=q[b]-q[b-(c+1)];
            long long sum=su[b]-su[b-(c+1)];
            cu+=y*(1ll*qq*b-sum);
        }
        an=min(an, cu);
    }
    cout<<an;
}