#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int n,c,a[500005],sum[500005],ans;
vector <int>d[500005];
int main(){
    cin>>n>>c;
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        sum[i]=sum[i-1];
        if (a[i]==c)sum[i]++;
        d[a[i]].push_back(i);
    }
    ans=sum[n];
    for (int i=1;i<=500000;i++){
        if (i==c)continue;
        if (d[i].size()>0)ans=max(ans,sum[n]+1);
        if (d[i].size()<=1)continue;
        int pre=1-sum[d[i][0]-1];
        for (int j=1,len=d[i].size();j<len;j++){
            ans=max(ans,sum[n]+j+1-sum[d[i][j]]+1-pre);
            pre=min(pre,j+1-sum[d[i][j]-1]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
//(i-j+1)-(sum[d[i]]-sum[d[j]-1])=i-sum[d[i]]+1-(j-sum[d[j]-1])