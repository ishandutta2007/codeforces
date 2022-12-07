#include <bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1e18;
main()
{
    //freopen("input.txt", "r", stdin);
    int x1, y1, x2, y2, n;
    cin>>x1>>y1>>x2>>y2>>n;
    int dx[n+1], dy[n+1];
    dx[0]=0, dy[0]=0;
    for(int a=0; a<n; a++)
    {
        char s;
        cin>>s;
        dx[a+1]=dx[a], dy[a+1]=dy[a];
        if(s=='U') dy[a+1]++;
        if(s=='D') dy[a+1]--;
        if(s=='L') dx[a+1]--;
        if(s=='R') dx[a+1]++;
    }
    int l=0, r=inf;
    while(r-l>1)
    {
        int mid=(l+r)>>1;
        int cx=dx[n]*(mid/n)+dx[mid%n], cy=dy[n]*(mid/n)+dy[mid%n];
        if(abs(x1+cx-x2)+abs(y1+cy-y2)<=mid) r=mid;
        else l=mid;
    }
    if(r!=inf) cout<<r;
    else cout<<-1;
}