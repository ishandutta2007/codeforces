#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
vector<int> G[maxn];
pair<int,int> arr[maxn];
int deg[maxn];
int main()
{
    memset(deg,0,sizeof(deg));
    int n;
    scanf("%d",&n);
    int sum=0;
    int diam=0;
    for(int i=1,temp;i<=n;i++)
    {
        scanf("%d",&temp);
        sum+=temp;
        arr[i]=make_pair(temp,i);
        if(temp>=2) diam++;
    }
    sort(arr+1,arr+1+n,greater<pair<int,int> >());
    if(sum<2*n-2)
        puts("NO");
    else{
        diam=min(diam+1,n-1);
        printf("YES %d\n%d\n",diam,n-1);
        int one=0x3f3f3f3f;
        int cnt=0;
        for(int i=1;i<n;i++)
        {
            if(arr[i].first==1&&arr[i+1].first==1)
            {
                one=i+1;
                break;
            }
            else{
                G[arr[i].second].push_back(arr[i+1].second);
                deg[arr[i].second]++;
                deg[arr[i+1].second]++;
            }
        }
        int now=1;
        while(one<=n)
        {
            while(deg[arr[now].second]>=arr[now].first) now++;
            deg[arr[now].second]++;
            G[arr[now].second].push_back(arr[one++].second);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<G[i].size();j++)
            {
                printf("%d %d\n",i,G[i][j]);
            }
        }
    }
    

}