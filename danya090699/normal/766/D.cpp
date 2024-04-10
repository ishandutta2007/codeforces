#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;
const int sz=3*1e6;
char buf[sz];
int fyk;
void g_st(string &s)
{
    while(buf[fyk]>='a' and buf[fyk]<='z')
    {
        s.push_back(buf[fyk]), fyk++;
    }
    fyk++;
}
void g_in(int &a)
{
    a=0;
    while(buf[fyk]>='0' and buf[fyk]<='9')
    {
        a=a*10+buf[fyk]-'0', fyk++;
    }
    fyk++;
}
void nst()
{
    fyk=0;
    gets(buf);
}
struct el
{
    int pr, sum=1, ant=-1;
};
el *ve;
map <string, int> sl;
int find_set(int v)
{
    if(ve[v].pr==v) return v;
    else
    {
        int v2=find_set(ve[v].pr);
        ve[v].pr=v2;
        return v2;
    }
}
int unite(int v1, int v2)
{
    if(v1==-1) return v2;
    else if(v2==-1) return v1;
    else
    {
        if(ve[v1].sum<ve[v2].sum) swap(v1, v2);
        ve[v1].sum+=ve[v2].sum;
        ve[v2].pr=v1;
        return v1;
    }
}
int main()
{
    int n, m, q;
    nst(), g_in(n), g_in(m), g_in(q), nst();
    ve=new el[n];
    for(int a=0; a<n; a++)
    {
        ve[a].pr=a;
        string s;
        g_st(s);
        sl[s]=sl.size()-1;
    }
    for(int a=0; a<m; a++)
    {
        int ty, s1, s2, er=0;
        string sl1, sl2;
        nst(), g_in(ty), g_st(sl1), g_st(sl2);
        s1=find_set(sl[sl1]);
        s2=find_set(sl[sl2]);
        if(ty==1)
        {
            if(s1!=s2)
            {
                if(ve[s1].ant!=s2)
                {
                    int v1=unite(s1, s2), v2=unite(ve[s1].ant, ve[s2].ant);
                    ve[v1].ant=v2;
                    if(v2!=-1) ve[v2].ant=v1;
                }
                else er=1;
            }
        }
        else
        {
            if(s1!=s2)
            {
                if(ve[s1].ant!=s2)
                {
                    int v1=unite(s1, ve[s2].ant), v2=unite(s2, ve[s1].ant);
                    ve[v1].ant=v2;
                    ve[v2].ant=v1;
                }
            }
            else er=1;
        }
        if(er) cout<<"NO\n";
        else cout<<"YES\n";
    }
    for(int a=0; a<q; a++)
    {
        int s1, s2, er=0;
        string sl1, sl2;
        nst(), g_st(sl1), g_st(sl2);
        s1=find_set(sl[sl1]);
        s2=find_set(sl[sl2]);
        if(s1==s2) cout<<"1\n";
        else if(ve[s1].ant==s2) cout<<"2\n";
        else cout<<"3\n";
    }
}