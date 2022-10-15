#include <bits/stdc++.h>

using namespace std;

const int N=1000+5;

int n,k;
bool ok[N][2*N];
int wat[N][2*N];
string s;

inline void go(int p,int cur)
{
    if(p==0)
    {
        return;
    }
    if(wat[p][cur]=='D') go(p-1,cur);
    if(wat[p][cur]=='W') go(p-1,cur-1);
    if(wat[p][cur]=='L') go(p-1,cur+1);
    cout<<char(wat[p][cur]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    cin>>s;
    s="."+s;
    ok[0][1001+0]=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='D')
        {
            for(int j=-i;j<=i;j++)
            {
                if(abs(j)==k && i!=n) continue;
                ok[i][1001+j]=ok[i-1][1001+j];
                wat[i][1001+j]='D';
            }
            continue;
        }
        if(s[i]=='W')
        {
            for(int j=-i;j<=i;j++)
            {
                if(abs(j)==k && i!=n) continue;
                ok[i][1001+j]=ok[i-1][1001+j-1];
                wat[i][1001+j]='W';
            }
            continue;
        }
        if(s[i]=='L')
        {
            for(int j=-i;j<=i;j++)
            {
                if(abs(j)==k && i!=n) continue;
                ok[i][1001+j]=ok[i-1][1001+j+1];
                wat[i][1001+j]='L';
            }
            continue;
        }
        if(s[i]=='?')
        {
         ///   cout<<"\t\t\t"<<i<<"\n\n";
            for(int j=-i;j<=i;j++)
            {
                if(abs(j)==k && i!=n) continue;
                if(ok[i-1][1001+j-1])
                {
                    ok[i][1001+j]=1;
                    wat[i][1001+j]='W';
                    continue;
                }
                if(ok[i-1][1001+j])
                {
                    ok[i][1001+j]=1;
                    wat[i][1001+j]='D';
                    continue;
                }
                if(ok[i-1][1001+j+1])
                {
                    ok[i][1001+j]=1;
                    wat[i][1001+j]='L';
                    continue;
                }
            }
        }
    }
   /// cout<<ok[2][1001-1]<<"\n";
   /// return 0;
    if(ok[n][1001-k])
    {
      //  cout<<"YES\n";
        go(n,1001-k);
        return 0;
    }
    if(ok[n][1001+k])
    {
        go(n,1001+k);
       // cout<<"YES\n";
        return 0;
    }
    cout<<"NO\n";

}

/**

**/