#include <bits/stdc++.h>
#define int long long
using namespace std;
const int sz=205, sz2=120;
struct el
{
    int ne[26], go[26], pr=0, sy, link=0, va=0;
};
el bor[sz];
int n, l, m=1;
int ma[sz2][sz][sz];
void um(int m1, int m2, int re)
{
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<m; b++)
        {
            ma[re][a][b]=-1;
            for(int c=0; c<m; c++) if(ma[m1][a][c]!=-1 and ma[m2][c][b]!=-1) ma[re][a][b]=max(ma[re][a][b], ma[m1][a][c]+ma[m2][c][b]);
        }
    }
}
main()
{
    //freopen("input.txt", "r", stdin);
    cin>>n>>l;
    int ar[n];
    for(int a=0; a<n; a++) cin>>ar[a];
    for(int a=0; a<26; a++) bor[0].ne[a]=-1;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int cu=0;
        for(int a=0; a<s.size(); a++)
        {
            int sy=s[a]-'a';
            if(bor[cu].ne[sy]==-1)
            {
                bor[cu].ne[sy]=m;
                for(int a=0; a<26; a++) bor[m].ne[a]=-1;
                bor[m].pr=cu, bor[m].sy=sy;
                m++;
            }
            cu=bor[cu].ne[sy];
        }
        bor[cu].va+=ar[a];
    }
    queue <int> qu;
    qu.push(0);
    while(qu.size()!=0)
    {
        int q=qu.size();
        for(int a=0; a<q; a++)
        {
            int nu=qu.front();
            int pr=bor[nu].pr, sy=bor[nu].sy;
            if(nu!=0 and pr!=0) bor[nu].link=bor[bor[pr].link].go[sy];
            bor[nu].va+=bor[bor[nu].link].va;
            for(int b=0; b<26; b++)
            {
                if(bor[nu].ne[b]!=-1)
                {
                    bor[nu].go[b]=bor[nu].ne[b];
                    qu.push(bor[nu].ne[b]);
                }
                else
                {
                    bor[nu].go[b]=bor[bor[nu].link].go[b];
                }
            }
            qu.pop();
        }
    }
    vector <int> le(1);
    le[0]=l;
    while(le.back()>1)
    {
        if(le.back()%2==0) le.push_back(le.back()/2);
        else le.push_back(le.back()-1);
    }
    for(int a=0; a<m; a++) for(int b=0; b<m; b++) ma[le.size()-1][a][b]=-1;
    int q=le.size();
    for(int a=0; a<m; a++)
    {
        for(int b=0; b<26; b++)
        {
            int ne=bor[a].go[b], pri;
            pri=bor[ne].va;
            ma[q-1][a][ne]=pri;
        }
    }
    for(int a=q-2; a>=0; a--)
    {
        if(le[a]%2==1) um(a+1, q-1, a);
        else um(a+1, a+1, a);
    }
    int an=0;
    for(int a=0; a<m; a++) an=max(an, ma[0][0][a]);
    cout<<an;
}