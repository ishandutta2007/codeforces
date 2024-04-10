#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int f[100];
int cine[100],y=0;
bool luat[100];
int sl[100],cnt=0;

bool ok(int i,int j)
{
        if(abs(i-j)==1) return 0;
        return 1;
}

bool gg=0;

void bkt(int strat)
{
        if(gg) return;
        if(strat==y)
        {
                gg=1;
                for(int j=1;j<=y;j++)
                {
                        for(int it=1;it<=f[sl[j]];it++)
                        {
                                cout<<(char)(sl[j]+'a');
                        }
                }
                cout<<"\n";
                return;
        }
        for(int j=1;j<=y;j++)
        {
                if(luat[j]==0 && ok(sl[strat],cine[j]))
                {
                        luat[j]=1;
                        sl[strat+1]=cine[j];
                        bkt(strat+1);
                        luat[j]=0;
                        if(gg) return;
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        sl[0]=1000;
        int t;
        cin>>t;
        while(t--)
        {
                gg=0;
                for(int i=0;i<26;i++) f[i]=0;
                string s;
                cin>>s;
                for(auto &x : s)
                {
                        f[x-'a']++;
                }
               // cout<<s<<" : ";
                y=0;
                for(int i=0;i<26;i++)
                {
                        if(f[i])
                        {
                                cine[++y]=i;
                        }
                }
                bkt(0);
                if(gg==0)
                {
                        cout<<"No answer\n";
                }
        }
        return 0;
}
/**

**/