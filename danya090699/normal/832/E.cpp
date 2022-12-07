//Come on, make Togliatti great again!
#include <bits/stdc++.h>
using namespace std;
struct el
{
    int nu, x, q;
};
el nel;
int main()
{
    //freopen("input.txt", "r", stdin);
    int n, m, qq, an=1, mod=1e9+7;
    int rev[5], um[5][5], mi[5][5];
    for(int a=0; a<5; a++)
    {
        for(int b=0; b<5; b++)
        {
            if((a*b)%5==1) rev[a]=b;
            um[a][b]=(a*b)%5;
            mi[a][b]=a-b;
            if(mi[a][b]<0) mi[a][b]+=5;
        }
    }
    cin>>n>>m;
    int ma[m][n];
    bool us[m];
    vector <el> ch;
    for(int a=0; a<m; a++) us[a]=0;
    for(int a=0; a<n; a++)
    {
        string s;
        cin>>s;
        for(int b=0; b<m; b++) ma[b][a]=s[b]-'a';
    }
    for(int a=0; a<n; a++)
    {
        int fo=-1;
        for(int b=0; b<m; b++) if(us[b]==0 and ma[b][a]!=0) fo=b;
        if(fo!=-1)
        {
            us[fo]=1;
            int va=rev[ma[fo][a]];
            for(int b=0; b<n; b++) ma[fo][b]=um[ma[fo][b]][va];
            nel.nu=fo, nel.x=va, nel.q=-1;
            ch.push_back(nel);
            for(int b=0; b<m; b++)
            {
                if(b!=fo)
                {
                    va=ma[b][a];
                    for(int c=0; c<n; c++) ma[b][c]=mi[ma[b][c]][um[ma[fo][c]][va]];
                    nel.nu=b, nel.x=fo, nel.q=va;
                    ch.push_back(nel);
                }
            }
        }
        else an=(1ll*an*5)%mod;
    }
    cin>>qq;
    for(int a=0; a<qq; a++)
    {
        string s;
        cin>>s;
        int ar[m], cu=an;
        for(int b=0; b<m; b++) ar[b]=s[b]-'a';
        for(int b=0; b<ch.size(); b++)
        {
            int nu=ch[b].nu, x=ch[b].x, q=ch[b].q;
            if(q==-1) ar[nu]=um[ar[nu]][x];
            else ar[nu]=mi[ar[nu]][um[ar[x]][q]];
        }
        for(int b=0; b<m; b++) if(us[b]==0 and ar[b]!=0) cu=0;
        cout<<cu<<"\n";
    }
}