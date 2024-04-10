#include <bits/stdc++.h>

using namespace std;

int main()
{
    const int M=20000;
    int n;
    scanf("%d",&n);
    vector<int> v(M+1,0);
    for(int i=0;i<n;i++)
    {
        int t;
        scanf("%d",&t);
        v[t]++;
    }
    int res=0;
    int l=0,r=M;
    while(l<r-1)
    {
        while(v[l]==0) l++;
        while(v[r]==0) r--;
        if(l>=r-1) break;
        int t=min(v[l],v[r]);
        v[l]-=t;
        v[r]-=t;
        v[l+1]+=t;
        v[r-1]+=t;
        res+=t;
    }
    printf("%d\n",res);
    return 0;
}