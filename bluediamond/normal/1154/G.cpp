#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int L=(int)1e7+7;
const int N=(int)1e6+7;

int n;
int f[L];
int id1[L];
int id2[L];
int v[N];

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        cin>>n;
        for(int i=1;i<=n;i++)
        {
                int x;
                cin>>x;
                v[i]=x;
                f[x]++;
                if(f[x]==1)
                {
                        id1[x]=i;
                }
                if(f[x]==2)
                {
                        id2[x]=i;
                }
        }
        ll ans=(1LL<<60);
        int ri,rj;
        for(int g=1;g<L;g++)
        {
                int e1=0,e2=0;
                for(int j=g;j<L;j+=g)
                {
                        if(f[j]==0) continue;
                        if(e1==0 && e2==0)
                        {
                                if(f[j]==1)
                                {
                                        e1=id1[j];
                                        continue;
                                }
                                else
                                {
                                        e1=id1[j];
                                        e2=id2[j];
                                        break;
                                }
                        }
                        e2=id1[j];
                        break;
                }
                if(e1==0 || e2==0) continue;
                ll give=v[e1]*(ll)v[e2]/(ll)g;
                ans=min(ans,give);
                if(give==ans)
                {
                        ri=e1;
                        rj=e2;
                }
        }
        if(ri>rj) swap(ri,rj);
        cout<<ri<<" "<<rj<<"\n";
        return 0;
}
/**

**/