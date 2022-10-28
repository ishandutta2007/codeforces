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
#include<bitset>
#define INF 100000000
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
vector<int> G[4];
int main()
{
    int n,ti,i,w;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&ti),G[ti].push_back(i);
    w=min(G[1].size(),G[2].size());
    w=min(int(G[3].size()),w);
    cout<<w<<endl;
    for(i=0;i<w;i++)
        printf("%d %d %d\n",G[1][i],G[2][i],G[3][i]);
    return 0;
}
// davidlee1999WTK 2014/
// srO myk Orz
//ios::sync_with_stdio(false);