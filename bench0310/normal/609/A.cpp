#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    sort(v.begin(),v.end(),greater<int>());
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=v[i];
        if(sum>=m)
        {
            printf("%d\n",i+1);
            break;
        }
    }
    return 0;
}