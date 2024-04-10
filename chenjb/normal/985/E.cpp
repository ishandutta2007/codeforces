#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cstdlib>
#include <stack>
#include <queue>
#define rep(i,n) for(int i=1;i<=n;++i)
#define pb push_back
#define mp make_pair
using namespace std;
int n,k,d;
int a[510000];
int f[510000];
int w[510000];
bool work()
{       
        memset(f,0,sizeof(f));

        f[0]=1;

        w[1]=-1;

        int head,tail=1;
        for(int i=1;i<=n;i++)
        {

            head=i;
            tail=max(tail,head);
            while (tail<n && a[tail+1]-a[i]<=d)tail++;

            if (head+k-1<=tail &&  f[i-1]>0)w[head+k-1]++,w[tail+1]--;

            f[i]=f[i-1]+w[i];

        }
    return f[n]>0;
}
int main()
{
        cin>>n>>k>>d;
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        sort(a+1,a+n+1);        
        if (work()){ puts("YES"); return 0; }
        puts("NO");
}