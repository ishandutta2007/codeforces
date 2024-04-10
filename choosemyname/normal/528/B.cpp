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
typedef pair<int,int> pii;
pii p[200010],q[200010];
int main()
{
    int n,n1,t1,t2;
    cin>>n;
    for(n1=1;n1<=n;n1++)
    {
        scanf("%d%d",&t1,&t2);
        p[n1]=make_pair(t1-t2,t1+t2);
    }
    sort(p+1,p+n+1);
    int x=0;
    for(n1=1;n1<=n;n1++)
    {
        while(x>0&&q[x].second>=p[n1].second)
            x--;
        x++;
        q[x]=p[n1];
    }
    int now=-maxlongint,ans=0;
    for(n1=1;n1<=x;n1++)
    {
        //cout<<q[n1].first<<' '<<q[n1].second<<endl;
        if(q[n1].first>=now)
        {
            ans++;
            now=q[n1].second;
        }
    }
    cout<<ans;
}