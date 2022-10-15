#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;


const int N=12;

int n,m;
int f[2][N+5];
int s[2][N+5];

int val[N+5],val_s[N+5];
vector<int>who[N+5];

int sol[N+5];
bool viz[N+5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
   cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>f[0][i]>>f[1][i];
        if(f[0][i]>f[1][i])
            swap(f[0][i],f[1][i]);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>s[0][i]>>s[1][i];
        if(s[0][i]>s[1][i])
            swap(s[0][i],s[1][i]);
    }
    for(int i=1;i<=n;i++)
    {
        int ap0=0,ap1=0;
        for(int j=1;j<=m;j++)
        {
            if(f[0][i]==s[0][j] && f[1][i]==s[1][j])
                continue;
            if(f[0][i]==s[0][j] || f[0][i]==s[1][j])
                ap0++;
            if(f[1][i]==s[0][j] || f[1][i]==s[1][j])
                ap1++;
        }
      ///  cout<<i<<" : "<<ap0<<" , "<<ap1<<"\n";
        if(ap0 && ap1==0)
        {
            val[i]=f[0][i];
            for(int j=1;j<=m;j++)
            {
                if(f[0][i]==s[0][j] && f[1][i]==s[1][j])
                    continue;
                if(f[0][i]==s[0][j] || f[0][i]==s[1][j])
                    who[i].push_back(j);
            }
        }
        if(ap0==0 && ap1)
        {
            val[i]=f[1][i];
            for(int j=1;j<=m;j++)
            {
                if(f[0][i]==s[0][j] && f[1][i]==s[1][j])
                    continue;
                if(f[1][i]==s[0][j] || f[1][i]==s[1][j])
                    who[i].push_back(j);
            }
        }
        for(int j=0;j<who[i].size();j++)
        {
            viz[who[i][j]]=1;
        }
        if(ap0 && ap1)
        {
            cout<<"-1\n";
            return 0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        int ap0=0,ap1=0;
        for(int j=1;j<=n;j++)
        {
            if(s[0][i]==f[0][j] && s[1][i]==f[1][j])
                continue;
            if(s[0][i]==f[0][j] || s[0][i]==f[1][j])
                ap0++;
            if(s[1][i]==f[0][j] || s[1][i]==f[1][j])
                ap1++;
        }
        if(ap0 && ap1==0)
            val_s[i]=s[0][i];
        if(ap0==0 && ap1)
            val_s[i]=s[1][i];
        if(ap0 && ap1)
        {
            ///<" : \n";
            cout<<"-1\n";
            return 0;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(val[i]==0)
            continue;
        bool ok=1;
        for(int j=0;j<who[i].size();j++)
        {
            int poz=who[i][j];
            if(val_s[poz]==val[i])
                continue;
            ok=0;
            break;
        }
        if(ok==1)
        {
        ///    cout<<" poz = "<<i<<" , val = "<<val[i]<<"\n";
            sol[++cnt]=val[i];
        }
    }
    sort(sol+1,sol+cnt+1);

    if(cnt==0)
    {
        cout<<"-1\n";
        return 0;
    }
    if(sol[1]==sol[cnt])
    {
        cout<<sol[1]<<"\n";
        return 0;
    }
    cout<<"0\n";
    return 0;
}
/**

**/