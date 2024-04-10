#include<bits/stdc++.h>
using namespace std;
#define MAX 250
int main()
{
    int n,m,x[MAX];
    char p[MAX][MAX];
    while(cin>>n>>m)
    {
        for(int i=0;i<m;i++)
        {
            int ans=0;
            for(int j=0;j<n;j++)
            {
                cin>>p[i][j];
                if(p[i][j]=='1')ans++;
            }
            if(ans==n)x[i]=0;
            else x[i]=1;
        }
        int ans=0,q=0,w=0;
        for(int i=0;i<m;i++)
        {
            if(x[i]==1)
            {
                if(q==0)q=1,w=i;
            }
            if(x[i]==0)
            {
                if(q==1)
                    ans=max(ans,i-w),q=0;
            }
        }
        if(q==1)ans=max(ans,m-w);
        cout<<ans<<endl;
    }
    return 0;
}