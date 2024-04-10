#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<long long> v(m,0);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        v[t-1]++;
    }
    long long res=0;
    for(int i=0;i<m;i++) for(int j=i+1;j<m;j++) res+=v[i]*v[j];
    printf("%I64d\n",res);
    return 0;
}