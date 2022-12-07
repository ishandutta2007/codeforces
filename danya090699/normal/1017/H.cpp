#include <bits/stdc++.h>
using namespace std;
const int sz=1e5+10, bl=350, mod=998244353;
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
int rev(int x){return po(x, mod-2);}
int f[sz*2], revf[sz*2], zap[sz][3];
int su[sz], q[sz];
bool comp(int a, int b)
{
    int nu1=zap[a][0]/bl, nu2=zap[b][0]/bl;
    if(nu1!=nu2) return nu1<nu2;
    else return zap[a][1]<zap[b][1];
}
bool comp2(int a, int b){return zap[a][2]<zap[b][2];}
unordered_map <int, unordered_map <int, int> > ma;
int cha(int x, int add)
{
    if(q[x]!=0)
    {
        auto it=ma[su[x]].find(q[x]);
        (*it).second--;
        if((*it).second==0) ma[su[x]].erase(q[x]);
    }
    q[x]+=add;
    if(q[x]!=0) ma[su[x]][q[x]]++;
}
int main()
{
    f[0]=1, revf[0]=1;
    for(int a=1; a<sz*2; a++)
    {
        f[a]=(1ll*f[a-1]*a)%mod;
        revf[a]=rev(f[a]);
    }
    //freopen("input.txt", "r", stdin);
    int n, m, q;
    cin>>n>>m>>q;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        su[ar[a]]++;
    }
    int p[q], an[q];
    for(int a=0; a<q; a++)
    {
        for(int b=0; b<3; b++) scanf("%d", &zap[a][b]);
        zap[a][0]--, zap[a][1]--, p[a]=a;
    }
    sort(p, p+q, comp);
    int l=0, r=-1;
    for(int a=0; a<q; a++)
    {
        int i=p[a];
        int lg=zap[i][0], rg=zap[i][1], k=zap[i][2];
        while(l<lg)
        {
            cha(ar[l], -1), l++;
        }
        while(l>lg)
        {
            l--, cha(ar[l], 1);
        }
        while(r>rg)
        {
            cha(ar[r], -1), r--;
        }
        while(r<rg)
        {
            r++, cha(ar[r], 1);
        }
        an[i]=1;
        for(auto it=ma.begin(); it!=ma.end(); it++)
        {
            int all=(*it).first+k;
            unordered_map <int, int> &cu=(*it).second;
            for(auto it=cu.begin(); it!=cu.end(); it++)
            {
                int qin=(*it).first, tot=(*it).second;
                int add=po((1ll*f[all]*revf[all-qin])%mod, tot);
                an[i]=(1ll*an[i]*add)%mod;
            }
        }
    }
    sort(p, p+q, comp2);
    int yk=0;
    while(yk<q)
    {
        int k=zap[p[yk]][2];
        int pref[n+1];
        pref[0]=1;
        for(int a=1; a<=n; a++) pref[a]=(1ll*pref[a-1]*((1ll*k*m+a)%mod))%mod;
        while(yk<q)
        {
            if(zap[p[yk]][2]==k)
            {
                int i=p[yk];
                int d=zap[i][1]-zap[i][0]+1;
                an[i]=(1ll*an[i]*pref[n-d])%mod;
                yk++;
            }
            else break;
        }
    }
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}