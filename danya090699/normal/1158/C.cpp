#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz];
int an[sz], timer;
void dfs(int v)
{
    reverse(sv[v].begin(), sv[v].end());
    for(int a=0; a<sv[v].size(); a++) dfs(sv[v][a]);
    an[v]=timer++;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    while(t)
    {
        t--;
        int n, ok=1;
        scanf("%d", &n);
        int ne[n];
        for(int a=0; a<n; a++)
        {
            an[a]=-1;
            scanf("%d", &ne[a]);
            if(ne[a]==-1) ne[a]=a+2;
            ne[a]--;
            if(ne[a]<n) sv[ne[a]].push_back(a);
        }
        vector <int> st;
        st.push_back(n);
        timer=0;
        for(int a=n-1; a>=0; a--)
        {
            if(an[a]==-1) dfs(a);
            while(st.size()>1 and an[st.back()]<an[a]) st.pop_back();
            if(ne[a]!=-1 and ne[a]!=st.back()) ok=0;
            st.push_back(a);
        }
        if(ok)
        {
            for(int a=0; a<n; a++) printf("%d ", an[a]+1);
            printf("\n");
        }
        else printf("-1\n");

        for(int a=0; a<n; a++) sv[a].clear();
    }
}