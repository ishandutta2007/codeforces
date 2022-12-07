#include <bits/stdc++.h>
using namespace std;
const int sz=256;
bool us[sz][2];
string an[sz][2];
bool comp(string &a, string &b)
{
    if(a.size())
    {
        if(b.size())
        {
            if(b.size()!=a.size()) return a.size()<b.size();
            else return a<b;
        }
        else return true;
    }
    else return false;
}
void tr(string s, string &to)
{
    if(comp(s, to)) to=s;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    an[240][0]="x", an[204][0]="y", an[170][0]="z";
    an[240][1]="x", an[204][1]="y", an[170][1]="z";
    for(int a=0; a<sz*2; a++)
    {
        string be;
        int v, vt;
        for(int b=0; b<sz; b++)
        {
            for(int c=0; c<2; c++)
            {
                if(us[b][c]==0)
                {
                    if(comp(an[b][c], be))
                    {
                        be=an[b][c], v=b, vt=c;

                    }
                }
            }
        }
        us[v][vt]=1;
        string to=an[v][vt];
        if(an[v][vt].size()>1) to="("+to+")";
        to="!"+to;
        tr(to, an[v^(sz-1)][0]), tr(to, an[v^(sz-1)][1]);
        for(int b=0; b<sz; b++)
        {
            for(int c=0; c<2; c++)
            {
                if(us[b][c])
                {
                    string s1=an[v][vt], s2=an[b][c];
                    if(vt==0) s1="("+s1+")";
                    if(c==0) s2="("+s2+")";
                    tr(s1+"&"+s2, an[v&b][0]);
                    tr(s2+"&"+s1, an[v&b][0]);
                    tr(s1+"&"+s2, an[v&b][1]);
                    tr(s2+"&"+s1, an[v&b][1]);
                    s1=an[v][vt], s2=an[b][c];
                    tr(s1+"|"+s2, an[v|b][0]);
                    tr(s2+"|"+s1, an[v|b][0]);
                    tr("("+s1+"|"+s2+")", an[v|b][1]);
                    tr("("+s2+"|"+s1+")", an[v|b][1]);
                }
            }
        }
    }
    int n;
    cin>>n;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        int x=0;
        for(int b=0; b<8; b++) if(s[b]=='1') x+=(1<<b);
        cout<<an[x][0]<<"\n";
    }
}