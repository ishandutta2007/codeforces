#include<bits/stdc++.h>
#define N 200000
const int inf=1e9;
using namespace std;
int T,n,x,ans;
multiset<int> s;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d",&n,&x),ans=0;
        for(int i=1,a;i<=n;++i)
            scanf("%d",&a),s.insert(a);
        while(!s.empty())
        {
            int a=*s.begin();
            s.erase(s.find(a));
            if(1ll*a*x<=inf && s.count(a*x))
                s.erase(s.find(a*x));
            else ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}