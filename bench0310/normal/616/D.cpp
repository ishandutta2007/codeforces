#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    vector<int> v(n);
    for(int i=0;i<n;i++) scanf("%d",&v[i]);
    vector<int> cnt(1000001,0);
    int now=1;
    cnt[v[0]]=1;
    int l=0,r=0;
    int a=0,b=0;
    auto update=[&]()->void
    {
        if(r-l>b-a) tie(a,b)={l,r};
    };
    while(r<n-1)
    {
        if(now<k||(now==k&&cnt[v[r+1]]>0))
        {
            r++;
            cnt[v[r]]++;
            if(cnt[v[r]]==1) now++;
            update();
        }
        else
        {
            cnt[v[l]]--;
            if(cnt[v[l]]==0) now--;
            l++;
            update();
        }
    }
    printf("%d %d\n",a+1,b+1);
    return 0;
}