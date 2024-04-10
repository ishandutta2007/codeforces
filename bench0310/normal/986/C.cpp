#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> x((1<<22),0);
vector<bool> val((1<<22),0);
int mask=0;

int go(int a)
{
    if(val[a]==1) return a;
    while(x[a]<n&&((a&(1<<x[a]))==0||go(a^(1<<x[a]))==-1)) x[a]++;
    if(x[a]==n) return -1;
    return go(a^(1<<x[a]));
}

void dfs(int a)
{
    val[a]=0;
    int t=0;
    while((t=go(mask^a))!=-1) dfs(t);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int m;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        int a;
        cin >> a;
        val[a]=1;
    }
    mask=(1<<n)-1;
    int res=0;
    for(int i=0;i<(1<<n);i++)
    {
        if(val[i]==1)
        {
            dfs(i);
            res++;
        }
    }
    cout << res << "\n";
    return 0;
}