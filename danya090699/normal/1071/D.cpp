#include <bits/stdc++.h>
using namespace std;
const int sz=1e6+10, sz2=300, sz3=8e3, inf=1e9;
int de[sz], dq[sz3], di[sz2][sz3], an[sz2][sz2];
map <vector <int>, int> se, se2;
map <int, int> dnu;
vector <int> sv[sz3];

int g_nu(int x)
{
    vector <int> ve;
    while(x>1)
    {
        int cu=de[x];
        ve.push_back(0);
        while(x%cu==0) x/=cu, ve.back()++;
    }
    sort(ve.begin(), ve.end(), greater <int>());
    if(se.find(ve)==se.end()) se[ve]=se.size()-1;
    return se[ve];
}

vector <int> st;
void dfs(int pr, int su, int q)
{
    if(dnu.find(q)==dnu.end()) dnu[q]=dnu.size()-1;
    dq[se2.size()]=dnu[q];
    se2[st]=se2.size()-1;
    for(int a=min(pr, 23-su); a>0; a--)
    {
        st.push_back(a);
        dfs(a, su+a, q*(a+1));
        st.pop_back();
    }
}
int main()
{
    for(int a=2; a<sz; a++)
    {
        if(de[a]==0)
        {
            for(int b=a; b<sz; b+=a) de[b]=a;
        }
    }
    for(int a=1; a<sz; a++) g_nu(a);

    dfs(inf, 0, 1);
    for(auto it=se2.begin(); it!=se2.end(); it++)
    {
        vector <int> cu=(*it).first;
        int v=(*it).second;
        cu.push_back(0);
        for(int a=0; a<cu.size(); a++)
        {
            vector <int> ne=cu;
            ne[a]++;
            sort(ne.begin(), ne.end(), greater <int>());
            while(ne.size())
            {
                if(ne.back()) break;
                else ne.pop_back();
            }
            if(se2.find(ne)!=se2.end()) sv[v].push_back(se2[ne]);

            ne=cu;
            if(ne[a])
            {
                ne[a]--;
                sort(ne.begin(), ne.end(), greater <int>());
                while(ne.size())
                {
                    if(ne.back()) break;
                    else ne.pop_back();
                }
                if(se2.find(ne)!=se2.end()) sv[v].push_back(se2[ne]);
            }
        }
    }

    for(auto it=se.begin(); it!=se.end(); it++)
    {
        int nu=(*it).second, nu2=se2[(*it).first];
        int us[se2.size()];
        for(int a=0; a<se2.size(); a++) us[a]=inf;
        us[nu2]=0;
        queue <int> qu;
        qu.push(nu2);
        for(int a=0; a<dnu.size(); a++) di[nu][a]=inf;
        while(qu.size())
        {
            int v=qu.front();
            di[nu][dq[v]]=min(di[nu][dq[v]], us[v]);
            for(int a=0; a<sv[v].size(); a++)
            {
                int ne=sv[v][a];
                if(us[ne]==inf)
                {
                    us[ne]=us[v]+1, qu.push(ne);
                }
            }
            qu.pop();
        }
    }

    for(int a=0; a<se.size(); a++)
    {
        for(int b=0; b<se.size(); b++)
        {
            an[a][b]=inf;
            for(int c=0; c<dnu.size(); c++) an[a][b]=min(an[a][b], di[a][c]+di[b][c]);
        }
    }

    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x=g_nu(x), y=g_nu(y);
        printf("%d\n", an[x][y]);
    }
}