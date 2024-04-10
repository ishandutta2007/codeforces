#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<string,int> pii;
pii nm[200005];
int p[100005][3],cou[100005],a;
int main()
{
    int n,i,last=0;
    //ios::sync_with_stdio(false);
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>nm[i].fi>>nm[i+n].fi;
        nm[i].se=nm[i+n].se=i;
    }
    sort(nm+1,nm+1+n*2);
    for(i=1;i<=n*2;i++)
    {
        //cout<<nm[i].fi<<endl;
        p[nm[i].se][++cou[nm[i].se]]=i;
    }
    //return 0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        if(p[a][1]>last) last=p[a][1];
        else if(p[a][2]>last) last=p[a][2];
        else
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);