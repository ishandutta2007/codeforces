#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=201;
int n,t,a[N];

int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]); if(a[i]<0) a[i]=-a[i];
        }
        for(int i=1;i<=n;i+=2) a[i]=-a[i];
        for(int i=1;i<=n;i++) printf("%d ",a[i]);
        puts("");
    }
    return 0;
}