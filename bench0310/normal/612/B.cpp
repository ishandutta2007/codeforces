#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        v[t-1]=i;
    }
    long long res=0;
    for(int i=0;i<n-1;i++) res+=max(v[i+1]-v[i],v[i]-v[i+1]);
    printf("%I64d\n",res);
    return 0;
}