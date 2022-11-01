#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int N=200005;
    int n,k,q;
    scanf("%d%d%d",&n,&k,&q);
    vector<int> d(N,0);
    for(int i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        d[a]++;
        d[b+1]--;
    }
    vector<int> sum(N,0);
    for(int i=1;i<N;i++) sum[i]=sum[i-1]+d[i];
    vector<int> res(N,0);
    for(int i=1;i<N;i++) res[i]=res[i-1]+(sum[i]>=k);
    while(q--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",res[b]-res[a-1]);
    }
    return 0;
}