#include <bits/stdc++.h>
using namespace std;
const int sz=(1<<12), inf=1e9;
int pref[sz][sz];
int main()
{
    //freopen("input.txt", "r", stdin);
    //ios_base::sync_with_stdio(false);
    int n, m, qq;
    cin>>n>>m>>qq;
    int va[n];
    for(int a=0; a<n; a++) cin>>va[a];
    pair <int, int> sub[1<<n];
    int q[1<<n];
    for(int a=0; a<(1<<n); a++)
    {
        sub[a].second=a, sub[a].first=0, q[a]=0;
        for(int i=0; i<n; i++) if((a&(1<<i))==0) sub[a].first+=va[i];
    }
    for(int a=0; a<m; a++)
    {
        char s[13];
        scanf("%12s", s);
        int mask=0;
        for(int i=0; i<n; i++) if(s[i]=='1') mask+=(1<<i);
        q[mask]++;
    }
    sort(sub, sub+(1<<n));
    for(int a=0; a<(1<<n); a++)
    {
        for(int b=0; b<(1<<n); b++)
        {
            pref[a][b]=q[a^sub[b].second];
            if(b) pref[a][b]+=pref[a][b-1];
        }
    }
    for(int a=0; a<qq; a++)
    {
        char s[13];
        int k, mask=0, an=0;
        scanf("%12s", s);
        scanf("%d", &k);
        for(int i=0; i<n; i++) if(s[i]=='1') mask+=(1<<i);
        int p=upper_bound(sub, sub+(1<<n), make_pair(k, inf))-sub;
        p--;
        if(p>=0) an=pref[mask][p];
        printf("%d\n", an);
    }
}