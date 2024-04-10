#include<bits/stdc++.h>
#define N 200000
using namespace std;
int T,n,endx,endy,nowx,nowy,maxx,maxy;
char s[N+5];
long long ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        endx=endy=1;
        scanf("%s",s);
        for(int i=0;s[i];++i)
            if(s[i]=='D') ++endx;
            else ++endy;
        ans=0;
        nowx=nowy=1;
        maxx=maxy=0;
        for(int i=0;s[i];++i)
            if(s[i]=='D') ans+=maxy+1,++nowx,maxx=n-endx;
            else ans+=maxx+1,++nowy,maxy=n-endy;
        ans+=1ll*(maxx+1)*(maxy+1);
        printf("%lld\n",ans);
    }
    return 0;
}