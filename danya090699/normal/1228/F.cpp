#include <bits/stdc++.h>
using namespace std;
const int sz=2e5+10;
vector <int> sv[sz];
int error, u, si[sz], us=0, us2=0, n;
void dfs(int v, int pr)
{
    //cout<<v<<" ";
    si[v]=1;
    vector <int> sp;
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs(ne, v), si[v]+=si[ne], sp.push_back(si[ne]);
    }
    sort(sp.begin(), sp.end());
    if(si[v]%2)
    {
        int t;
        if(sp.size()==0) t=0;
        else if(sp.size()==2 and sp[1]==sp[0]) t=0;
        else error=1;
    }
    else
    {
        //cout<<v<<" ";
        if(sp.size()==1)
        {
            if(si[v]==2) u=v+1;
            else error=1;
        }
        else if(sp.size()==2)
        {
            if(sp[0]+1!=sp[1]) error=1;
        }
        else if(sp.size()==3)
        {
            if(sp[0]==sp[1] and sp[0]*2+1==sp[2]) u=v+1;
            else error=1;
        }
        else error=1;
    }
}
vector <int> st;
set <int> an;
void dfs2(int v, int pr)
{
    st.push_back(v);
    if(sv[v].size()==1 and st.size()==n*2-2 and us==0)
    {
        //cout<<st[n-1]<<" "<<st[n-2];
        us=1;
        error=0, dfs(st[n-1], st[n-1]);
        if(error==0) an.insert(u);
        error=0, dfs(st[n-2], st[n-2]);
        if(error==0) an.insert(u);
    }
    if(sv[v].size()==1 and st.size()==n*2-1 and us2==0)
    {
        us2=1;
        error=0, dfs(st[n-1], st[n-1]);
        if(error==0) an.insert(u);
    }
    for(int a=0; a<sv[v].size(); a++)
    {
        int ne=sv[v][a];
        if(ne!=pr) dfs2(ne, v);
    }
    st.pop_back();
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n;
    for(int a=0; a<(1<<n)-3; a++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        u--, v--;
        sv[u].push_back(v);
        sv[v].push_back(u);
    }
    for(int a=0; a<(1<<n)-2; a++)
    {
        if(sv[a].size()==1)
        {
            //cout<<a<<" ";
            dfs2(a, a);
            break;
        }
    }
    cout<<an.size()<<"\n";
    for(auto it=an.begin(); it!=an.end(); it++) cout<<(*it)<<" ";
}