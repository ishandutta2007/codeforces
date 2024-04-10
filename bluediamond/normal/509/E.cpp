#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=500000+5;

int n,s[N];
string lol;

inline int gt(int st,int dr)
{
    return s[dr]-s[st-1];
}

ld ans=0;

inline void di(ld a,ld b)
{
    ans+=a/b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>lol;
    n=lol.size();
    lol="."+lol;
    for(int i=1;i<=n;i++)
    {
        if(lol[i]=='A') s[i]=1;
        if(lol[i]=='E') s[i]=1;
        if(lol[i]=='I') s[i]=1;
        if(lol[i]=='O') s[i]=1;
        if(lol[i]=='U') s[i]=1;
        if(lol[i]=='Y') s[i]=1;
        s[i]+=s[i-1];
    }
    ll now=0LL;
    int st=0;
    int dr=n+1;
    for(int cnt=1;cnt<=n;cnt++)
    {
        if(cnt<=(n+1)/2)
        {
            st++;
            dr--;
            now+=gt(st,dr);
        }
        else
        if(n%2==0 && cnt==n/2+1)
        {

        }
        else
        {
            now-=gt(st,dr);
            st--;
            dr++;
        }
        di(now,cnt);
       /// cout<<cnt<<" "<<now<<"\n";
    }
    cout<<fixed<<setprecision(6)<<ans<<"\n";

    return 0;
}