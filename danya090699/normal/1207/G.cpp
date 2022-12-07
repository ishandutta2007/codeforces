#include <bits/stdc++.h>
using namespace std;
const int bl=350, sz=4e5+10;
int pr[sz], bor[sz][26], cnt[sz], an[sz], q=1;
char prsy[sz];
vector <pair <int, int> > sp[sz];
vector <int> sv[sz];
void dfs(int v)
{
    //cout<<v<<" ";
    int u=v, s=0;
    for(int a=0; (a<bl and u!=0 and s!=-1); a++)
    {
        s=bor[s][prsy[u]-'a'];
        if(s!=-1) cnt[s]++;
        u=pr[u];
    }
    for(int a=0; a<sp[v].size(); a++)
    {
        int s=sp[v][a].first, nu=sp[v][a].second;
        an[nu]=cnt[s];
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        dfs(sv[v][a]);
    }
    u=v, s=0;
    for(int a=0; (a<bl and u!=0 and s!=-1); a++)
    {
        s=bor[s][prsy[u]-'a'];
        if(s!=-1) cnt[s]--;
        u=pr[u];
    }
}
int f(string &s, int le)
{
    int n=s.size(), re=0;
    int zf[n], l=0, r=-1;
    zf[0]=0;
    for(int a=1; a<n; a++)
    {
        zf[a]=0;
        if(r>=a) zf[a]=min(zf[a-l], r-a+1);
        while(a+zf[a]<n)
        {
            if(s[zf[a]]==s[a+zf[a]]) zf[a]++;
            else break;
        }
        if(a+zf[a]-1>r) l=a, r=a+zf[a]-1;

        if(zf[a]==le) re++;
    }
    return re;
}
main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    for(int a=1; a<=n; a++)
    {
        int ty;
        scanf("%d", &ty);
        if(ty==2) scanf("%d", &pr[a]);
        scanf("%s", prsy+a);
        sv[pr[a]].push_back(a);
    }
    int m;
    cin>>m;
    for(int a=0; a<26; a++) bor[0][a]=-1;
    for(int a=0; a<m; a++)
    {
        int v;
        scanf("%d", &v);
        string st;
        cin>>st;
        reverse(st.begin(), st.end());
        if(st.size()<bl)
        {
            int s=0;
            for(int b=0; b<st.size(); b++)
            {
                int ne=st[b]-'a';
                if(bor[s][ne]==-1)
                {
                    bor[s][ne]=q++;
                    for(int i=0; i<26; i++) bor[q-1][i]=-1;
                }
                s=bor[s][ne];
            }
            //cout<<s<<" ";
            sp[v].push_back({s, a});
        }
        else
        {
            int l=st.size();
            st.push_back('#');
            while(v)
            {
                st.push_back(prsy[v]), v=pr[v];
            }
            an[a]=f(st, l);
        }
    }
    dfs(0);
    for(int a=0; a<m; a++) printf("%d\n", an[a]);
}