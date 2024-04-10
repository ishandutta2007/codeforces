#include<bits/stdc++.h>
#define y1 lmyakioi
using namespace std;

const int maxn=100005;
const int dx[4]={0,0,-1,1};
const int dy[4]={1,-1,0,0};

int n;

int x1,y1,x2,y2;
long long cx,cy;

int ptx[maxn],pty[maxn];
int t[maxn];

inline long long absl(long long a){
    return (a<0?-a:a);
}
bool chk(long long d){
    long long f=d/n,g=d%n;
    long long tx=f*ptx[n]+ptx[g],ty=f*pty[n]+pty[g];
    long long ds=absl(tx-cx)+absl(ty-cy);
    return ds<=d;
}

int main(){
    ios::sync_with_stdio(0);
    cin>>x1>>y1>>x2>>y2;
    cx=x2-x1,cy=y2-y1;
    cin>>n;
    char _[maxn];
    cin>>_;
    for(int i=1;i<=n;i++){
        switch (_[i-1]){
            case 'U': t[i]=1; break;
            case 'D': t[i]=2; break;
            case 'L': t[i]=3; break;
            case 'R': t[i]=4; break;
        }
        ptx[i]=ptx[i-1]+dx[t[i]-1];
        pty[i]=pty[i-1]+dy[t[i]-1];
    }
    long long l=0,r=0x3fff3fff3fff3fff;
    while(r-l>3){
        long long m=(l+r)>>1;
        if(chk(m)){
            r=m;
        }else l=m;
    }
    for(long long i=l;i<=r;i++){
        if(chk(i)){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}