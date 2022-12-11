#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=2e5+50;
LL inf=1e12;
int n,m,k,a[N],r1,r2;bool fa[N],fb[N];LL ans;
int read(){
    int x=0,c;
    while(!isdigit(c=getchar()));
    while(isdigit(c))x=x*10+c-48,c=getchar();
    return x;
}
priority_queue<int,vector<int>,greater<int> >A,B,C,D,E;
int main(){
    n=read();m=read();k=read();r1=m-k;r2=m-k;
    if(k>m)puts("-1"),exit(0);
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=read();i;i--)fa[read()]=1;
    for(int i=read();i;i--)fb[read()]=1;
    for(int i=1;i<=n;i++){
        if(fa[i])fb[i]?A.push(a[i]):D.push(a[i]);
        else fb[i]?B.push(a[i]):C.push(a[i]);
    }
    for(int i=1;i<=m;i++){
        LL v1=A.size()?A.top():inf,v2=B.size()&&r1?B.top():inf;
        LL v3=C.size()&&r1&&r2?C.top():inf,v4=D.size()&&r2?D.top():inf;
        LL v5=B.size()&&D.size()&&E.size()?B.top()+D.top()+E.top():inf;
        LL mn=min(v1,min(v2,min(v3,min(v4,v5))));
        if(mn==inf)puts("-1"),exit(0);ans+=mn;
        if(v1==mn)A.pop();
        else if(v2==mn)B.pop(),r1--;
        else if(v3==mn)E.push(-v3),C.pop(),r1--,r2--;
        else if(v4==mn)D.pop(),r2--;
        else B.pop(),D.pop(),E.pop();
    }
    cout<<ans;
    return 0;
}