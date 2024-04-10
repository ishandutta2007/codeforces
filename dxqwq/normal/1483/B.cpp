#include <bits/stdc++.h>
using namespace std;
 
const int N=100010;
 
int T,n,a[N];
int nxt[N],pre[N];
set<int> flag;
vector<int> ans;
 
void init()
{
    flag.clear();
    ans.clear();
}
 
void del(int p)
{
    if (nxt[p]==p)
    {
        flag.erase(p);
        return;
    }
    nxt[pre[p]]=nxt[p];
    pre[nxt[p]]=pre[p];
    flag.erase(pre[p]);
    flag.erase(p);
    if (__gcd(a[pre[p]],a[nxt[p]])==1)
    {
        flag.insert(pre[p]);
    }
}
 
int main()
{
    scanf("%d",&T);
    while (T--)
    {
        init();
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i=1;i<=n;i++)
        {
            nxt[i]=(i==n?1:i+1);
            pre[i]=(i==1?n:i-1);
            if (__gcd(a[i],a[nxt[i]])==1)
            {
                flag.insert(i);
            }
        }
        auto it=flag.lower_bound(1);
        while (it!=flag.end())
        {
            int p=nxt[*it];
            ans.push_back(p);
            del(p);
            it=flag.lower_bound(p);
            if (it==flag.end()) it=flag.lower_bound(1);
        }
        printf("%d ",(int)ans.size());
        for (int i:ans) printf("%d ",i);
        printf("\n");
    }
    getchar(); getchar();
    return 0;
}