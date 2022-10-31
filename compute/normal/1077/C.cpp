#include<bits/stdc++.h>
using namespace std;
const int maxa=1e6+7;
vector<int> arr[maxa];
int main()
{
    int n;
    scanf("%d",&n);
    long long sum=0;
    for(int i=1,temp;i<=n;i++)
    {
        scanf("%d",&temp);
        arr[temp].push_back(i);
        sum+=temp;
    }
    vector<int> ans;
    for(int i=1;i<=1000000;i++)
    {
        if(i>sum||(sum-i)/2>1000000) continue;
        if(arr[i].size()>0)
        {
            if((sum-i)%2==0)
            {
                if(arr[(sum-i)/2].size())
                {
                    if((sum-i)/2==i&&arr[(sum-i)/2].size()==1) continue;
                    for(int j=0;j<arr[i].size();j++)
                    {
                        ans.push_back(arr[i][j]);
                    }
                }
            }
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        printf("%d ",ans[i]);
    }
    printf("\n");

}