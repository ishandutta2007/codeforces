#include <bits/stdc++.h>
using namespace std;
const int sz=1e5, sz2=100;
int mod, pa[sz][sz2];
map <int, int> ma;
int po(int x, int y)
{
    int re=1;
    while(y)
    {
        if(y&1) re=(1ll*re*x)%mod;
        y>>=1;
        x=(1ll*x*x)%mod;
    }
    return re;
}
int main()
{
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    int u, v;
    cin>>u>>v>>mod;
    for(int a=0; a<sz; a++)
    {
        int cu=u;
        for(int b=0; b<sz2; b++)
        {
            pa[a][b]=rand()%3+1;
            if(pa[a][b]==1) cu=(cu+1)%mod;
            if(pa[a][b]==2) cu=(cu+mod-1)%mod;
            if(pa[a][b]==3) cu=po(cu, mod-2);
        }
        ma[cu]=a;
    }
    bool fo=0;
    while(fo==0)
    {
        int cu=v;
        vector <int> sp;
        for(int a=0; a<sz2; a++)
        {
            sp.push_back(rand()%3+1);
            if(sp.back()==1) cu=(cu+mod-1)%mod;
            if(sp.back()==2) cu=(cu+1)%mod;
            if(sp.back()==3) cu=po(cu, mod-2);
            if(ma.find(cu)!=ma.end())
            {
                fo=1;
                int i=ma[cu];
                cout<<sz2+sp.size()<<"\n";
                for(int b=0; b<sz2; b++) cout<<pa[i][b]<<" ";
                reverse(sp.begin(), sp.end());
                for(int b=0; b<sp.size(); b++) cout<<sp[b]<<" ";
                break;
            }
        }
    }
}