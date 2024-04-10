#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=(int)3e5+7;

int n,m;
int nxt[N];
int res[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
                nxt[i]=i+1;
        }
        while(m--)
        {
                int tl,tr,p;
                cin>>tl>>tr>>p;
                for(int i=tl;i<=tr;)
                {
                        if(i==p)
                        {
                                i++;
                                continue;
                        }
                        int j=nxt[i];
                        if(i<p)
                        {
                                nxt[i]=max(nxt[i],p);
                        }
                        else
                        {
                                nxt[i]=max(nxt[i],tr+1);
                        }
                        if(res[i]==0)
                        {
                                res[i]=p;
                        }
                        i=j;
                }
        }
        for(int i=1;i<=n;i++)
        {
                cout<<res[i]<<" ";
        }
        cout<<"\n";
        return 0;
}