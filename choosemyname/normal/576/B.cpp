#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
#include<bitset>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int go[100010],v[100010],d[100010];
int dfs(int i)
{
    v[i]=1;
    if(v[go[i]])
    {
        d[i]=1;
        return 1;
    }
    else
        return d[i]=dfs(go[i])+1;
}
int main()
{
    int n,n1;
    cin>>n;
    int al=0;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%d",&go[n1]);
        if(go[n1]==n1)
            al=n1;
    }
    if(al)
    {
        cout<<"YES\n";
        for(n1=1;n1<=n;n1++)
            if(n1!=al)
                cout<<n1<<' '<<al<<endl;
        return 0;
    }
    for(n1=1;n1<=n;n1++)
        if(!v[n1])
        {
            int k=dfs(n1);
            if(k==2)
                al=n1;
            if(k%2!=0)
            {
                cout<<"NO";
                return 0;
            }
        }
    if(al==0)
    {
        cout<<"NO";
        return 0;
    }
        cout<<"YES\n";
    cout<<al<<' '<<go[al]<<endl;
    for(int i=1;i<=n;i++)
        if(i!=al&&i!=go[al])
        {
            if(d[i]%2==0)
                cout<<i<<' '<<al<<endl;
            else
                cout<<i<<' '<<go[al]<<endl;
        }
}