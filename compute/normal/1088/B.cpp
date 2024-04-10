#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
vector<long long> all;
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0,temp;i<n;i++)
    {
        scanf("%d",&temp);
        all.push_back(temp);
    }
    sort(all.begin(),all.end());
    all.erase(unique(all.begin(),all.end()),all.end());
    long long sum=0;
    for(int i=0;i<k;i++)
    {
        long long now=0;
        if(i>=all.size()) now=0;
        else now=all[i]-sum;
        printf("%lld\n",now);
        sum+=now;
    }
}