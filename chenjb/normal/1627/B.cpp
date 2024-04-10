#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
int n,m;
double midx,midy;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        scanf("%d%d",&n,&m);
        midx=n;
        midy=m;
        static vector<int> q; q.clear();
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int ans=0;
            ans=max(ans,abs(i-1)+abs(j-1));
            ans=max(ans,abs(i-1)+abs(j-m));
            ans=max(ans,abs(i-n)+abs(j-1));
            ans=max(ans,abs(i-n)+abs(j-m));
            q.pb(ans);
        }
        sort(q.begin(),q.end());
        for(auto p:q)
        {
            //cout<<p.first<<" "<<p.second<<endl;
            
            printf("%d ",p);
        }
        puts("");
    }    
    return 0;
}