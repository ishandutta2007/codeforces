#include <bits/stdc++.h>
using namespace std;
const int sz=51e5, sz2=2e5;
vector <int> ch[sz], de[sz2];
int pr[sz2][1<<7], be[sz][8];
bool pri[sz];
int su[20][sz2], yk[20];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, q;
    cin>>n>>q;
    int ar[n];
    for(int a=0; a<n; a++)
    {
        scanf("%d", &ar[a]);
        ch[ar[a]].push_back(a);
    }
    for(int a=2; a<sz; a++)
    {
        if(pri[a]==0)
        {
            for(int b=a; b<sz; b+=a)
            {
                pri[b]=1;
                int x=b, ok=0;
                while(x%a==0)
                {
                    x/=a, ok^=1;
                }
                if(ok)
                {
                    for(int c=0; c<ch[b].size(); c++) de[ch[b][c]].push_back(a);
                }
            }
        }
    }
    pair <pair <int, int>, int> zap[q];
    for(int a=0; a<q; a++)
    {
        scanf("%d%d", &zap[a].first.first, &zap[a].first.second);
        zap[a].first.first--, zap[a].first.second--, zap[a].second=a;
    }
    sort(zap, zap+q);
    for(int a=n-1; a>=0; a--)
    {
        int dq=de[a].size();
        for(int mask=0; mask<(1<<dq); mask++)
        {
            int va=1, bad=0;
            for(int i=0; i<dq; i++)
            {
                if(mask&(1<<i)) va*=de[a][i];
                else bad++;
            }
            for(int i=0; i<=7; i++) if(be[va][i]) su[bad+i][be[va][i]]++;
            pr[a][mask]=be[va][bad];
            be[va][bad]=a;
        }
    }
    int ykq=0, an[q];
    for(int a=0; a<n; a++)
    {
        for(int i=0; i<=14; i++)
        {
            while(yk[i]<n)
            {
                if(su[i][yk[i]]==0) yk[i]++;
                else break;
            }
        }
        while(ykq<q)
        {
            int l=zap[ykq].first.first, r=zap[ykq].first.second, nu=zap[ykq].second;
            if(l==a)
            {
                for(int i=0; i<=14; i++)
                {
                    if(yk[i]<=r)
                    {
                        an[nu]=i;
                        break;
                    }
                }
                ykq++;
            }
            else break;
        }
        int dq=de[a].size();
        for(int mask=0; mask<(1<<dq); mask++)
        {
            int va=1, bad=0;
            for(int i=0; i<dq; i++)
            {
                if(mask&(1<<i)) va*=de[a][i];
                else bad++;
            }
            be[va][bad]=pr[a][mask];
            for(int i=0; i<=7; i++) if(be[va][i]) su[bad+i][be[va][i]]--;
        }
    }
    for(int a=0; a<q; a++) printf("%d\n", an[a]);
}