#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1010;
int p[N];
bool st[N];
int res;
void dfs(int x)
{
    x=p[x];
    if(st[x])
    {
        res=x;
        return;
    }
    st[x]=true;
    dfs(x);
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++ )scanf("%d",&p[i]);
    for (int i = 1; i <= n; i ++ )
    {
        memset(st, 0, sizeof st);
        int x=i;
        st[x]=true;
        dfs(x);
		//whiledfs
        /*
        while(true)
        {
            x=p[x];
            if(st[x])break;
            st[x]=true;
        }
        */
        cout<<res<<" ";
    }
    return 0;
}