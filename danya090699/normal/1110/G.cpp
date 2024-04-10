#include <bits/stdc++.h>
using namespace std;
const int sz=5e5+10;
vector <int> sv[sz];
char s[sz];
bool draw(int n)
{
    if(n<3) return 1;
    int wq=0;
    for(int a=0; a<n; a++) if(s[a]=='W') wq++;
    if(n==3)
    {
        if(wq<2) return 1;
        else return 0;
    }
    int leaf=0;
    for(int a=0; a<n; a++)
    {
        if(sv[a].size()>3) return 0;
        if(sv[a].size()==3)
        {
            int q=0;
            for(int b=0; b<sv[a].size(); b++) if(sv[sv[a][b]].size()>1) q++;
            if(q>1) return 0;
        }
        if(s[a]=='W')
        {
            if(sv[a].size()>1) return 0;
            else if(sv[sv[a][0]].size()>2) return 0;
        }
        if(sv[a].size()==1) leaf++;
    }
    if(leaf==2)
    {
        if(wq==2 and n%2==1) return 0;
        else return 1;
    }
    if(leaf==3)
    {
        if(wq and n%2==0) return 0;
        else return 1;
    }
    if(leaf==4)
    {
        if(n%2==1) return 0;
        else return 1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int t;
    cin>>t;
    for(int a=0; a<t; a++)
    {
        int n;
        scanf("%d", &n);
        for(int a=0; a<n-1; a++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            u--, v--;
            sv[u].push_back(v);
            sv[v].push_back(u);
        }
        scanf("%s", s);
        if(draw(n)) printf("Draw\n");
        else printf("White\n");
        for(int a=0; a<n; a++) sv[a].clear();
    }
}