#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    string a,b;
    cin>>a>>b;
    int mark[1000];
    memset(mark,0,sizeof(mark));
    for(int i=0;i<n;i++)
    {
        if(a[i]==b[0])
        {
            int flag=1,j;
            for(j=1;j<m&&i+j<n;j++)
            {
                if(a[i+j]!=b[j])
                {
                    flag=0;
                    break;
                }
            }
            if(flag&&j==m) mark[i]=1;
        }
    }
    while(q--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        int cnt=0;
        for(int i=l-1;i<=r-1;i++)
        {
            if(mark[i]==1&&i+m-1<=r-1)
                cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}