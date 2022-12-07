#include <bits/stdc++.h>
using namespace std;
const int mod=2520, sz=1e3+10;
int cnu[sz][mod], an[sz*mod], cq=0;
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int va[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &va[a]);
        if(va[a]<0) va[a]+=((-va[a])/mod+1)*mod;
        va[a]=va[a]%mod;
    }
    vector <int> sv[n];
    for(int a=0; a<n; a++)
    {
        int q;
        scanf("%d", &q);
        sv[a].resize(q);
        for(int b=0; b<q; b++)
        {
            scanf("%d", &sv[a][b]);
            sv[a][b]--;
        }
    }
    for(int a=0; a<n; a++) for(int b=0; b<mod; b++) cnu[a][b]=-1;
    for(int a=0; a<n; a++)
    {
        for(int b=0; b<mod; b++)
        {
            if(cnu[a][b]==-1)
            {
                int v=a, os=b;
                vector <pair <int, int> > sp;
                while(cnu[v][os]==-1)
                {
                    cnu[v][os]=-2;
                    sp.push_back({v, os});
                    os=(os+va[v])%mod;
                    v=sv[v][os%sv[v].size()];
                }
                int cu;
                if(cnu[v][os]==-2)
                {
                    cu=cq++;
                    set <int> se;
                    while(cnu[v][os]!=cu)
                    {
                        se.insert(v);
                        cnu[v][os]=cu;
                        os=(os+va[v])%mod;
                        v=sv[v][os%sv[v].size()];
                    }
                    an[cu]=se.size();
                }
                else cu=cnu[v][os];

                for(int c=0; c<sp.size(); c++)
                {
                    cnu[sp[c].first][sp[c].second]=cu;
                }
            }
        }
    }
    int q;
    cin>>q;
    for(int a=0; a<q; a++)
    {
        int v, val;
        scanf("%d%d", &v, &val);
        v--;
        if(val<0) val+=((-val)/mod+1)*mod;
        val=val%mod;
        printf("%d\n", an[cnu[v][val]]);
    }
}