#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int nax=(int)2e5+7;
string ss;
string t;

int p[nax];
int s[nax];

int main()
{

        bool ishome=0;

        if(ishome)
        {
                freopen("__input__","r",stdin);
        }
        else
        {
                ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        }

        cin>>ss>>t;
        int n=(int)ss.size();
        int m=(int)t.size();
        ss="."+ss;
        t="."+t;

        for(int i=1;i<=m;i++)
        {
                p[i]=p[i-1]+1;
                while(ss[p[i]]!=t[i])
                        p[i]++;
        }

        s[m+1]=n+1;
        for(int i=m;i>=1;i--)
        {
                s[i]=s[i+1]-1;
                while(ss[s[i]]!=t[i])
                        s[i]--;
        }

        int mx=0;
        for(int i=0;i<=m;i++)
        {
                int dif=s[i+1]-p[i];
                mx=max(mx,dif-1);
        }
        cout<<mx<<"\n";

        return 0;
}