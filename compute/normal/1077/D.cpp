#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+7;
int s[maxn];
bool check(int now,int k)
{
    int var=0;
    for(int i=1;i<maxn;i++)
    {
        var+=s[i]/now;
    }
    return var<k;//<klrlyesrno
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    memset(s,0,sizeof(s));
    for(int i=0,temp;i<n;i++)
    {
        scanf("%d",&temp);
        s[temp]++;
    }
    int high=n,low=1;
    while(high-low>1)
    {
        //cout<<high<<"*"<<low<<endl;
        int mid=(high+low)>>1;
        if(check(mid,k)) high=mid;
        else low=mid;
    }
    vector<int> ans;
    for(int i=1;i<maxn;i++)
    {
        for(int j=0;j<s[i]/low;j++)
            ans.push_back(i);
    }
    for(int i=0;i<k;i++)//vectork
        printf("%d ",ans[i]);
    printf("\n");
}