#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1000+5;

string best[N];
string inv[N];

int ans[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    s="."+s;
    best[1]=inv[1]=s[1];
    for(int i=2;i<=n;i++)
    {
        /// best[i]
        best[i]=best[i-1]+s[i];
        string value=inv[i-1];
        value+=s[i];
        reverse(value.begin(),value.end());
        best[i]=min(best[i],value);
        /// inv[i]
        inv[i]=inv[i-1]+s[i];
        value=best[i-1];
        value+=s[i];
        reverse(value.begin(),value.end());
        inv[i]=max(inv[i],value);
    }
    int t=1;
    for(int poz=n;poz>=2;poz--)
    {
        int sol=-1;
        if(t==1)
        {
            if(best[poz]==best[poz-1]+s[poz])
            {
                sol=0;
            }
            else
            {
                sol=1;
                t=2;
            }
        }
        else
        {
            if(inv[poz]==inv[poz-1]+s[poz])
            {
                sol=0;
            }
            else
            {
                sol=1;
                t=1;
            }
        }
        ans[poz]=sol;
    }
   /// cout<<best[n]<<"\n";
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
/**



**/