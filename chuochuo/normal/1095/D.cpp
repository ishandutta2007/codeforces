#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int n,k,a[MAXN][2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i][0],&a[i][1]);
    if(n==3)
    {
        printf("%d %d %d\n",1,2,3);
        return 0;
    }
    vector<int> ans;
    ans.push_back(1);
    int to=a[1][0];
    if(a[to][0]!=a[1][1]&&a[to][1]!=a[1][1]) to=a[1][1];
    int last=1;
    do
    {
        ans.push_back(to);
        int tmp=last;
        last=to;
        if(a[tmp][0]==to) to=a[tmp][1]; else to=a[tmp][0];
    }while(to!=1);
    for(auto it:ans) printf("%d ",it);
    return 0;
}