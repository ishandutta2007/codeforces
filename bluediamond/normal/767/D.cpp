#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N=1000000;

int n,a1[N+5],a2[N+5];
int m;
int t;

struct info {
    int x,i;
};
info b[N+5];

bool cmp(info a,info b) {
    return a.x>b.x;
}

int kek[2*N+5];

bool ok(int cnt) {
    for(int i=cnt;i>=1;i--)
        a2[i]=b[cnt+1-i].x;
    int len=n+cnt;
    int p1=1;
    int p2=1;
    for(int i=1;i<=len;i++) {
        if(p1>n)
            kek[i]=a2[p2++];
        else
            if(p2>cnt)
                kek[i]=a1[p1++];
            else
                if(a1[p1]<a2[p2])
                    kek[i]=a1[p1++];
                else
                    kek[i]=a2[p2++];
    }
    int cald=0;
    for(int st=1;st<=len;st+=t) {
        int dr=min(len,st+t-1);
        for(int j=st;j<=dr;j++) {
            if(kek[j]<cald)
                return 0;
        }
        cald++;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>t;
    for(int i=1;i<=n;i++)
        cin>>a1[i];
    sort(a1+1,a1+n+1);
    for(int i=1;i<=m;i++) {
        cin>>b[i].x;
        b[i].i=i;
    }
    sort(b+1,b+m+1,cmp);
    int r=0,pas=(1<<19);
    while(pas) {
        if(r+pas<=m && ok(r+pas))
            r+=pas;
        pas/=2;
    }
    if(r==0 && ok(0)==0)
        cout<<"-1\n";
    else {
        cout<<r<<"\n";
        for(int i=1;i<=r;i++)
            cout<<b[i].i<<" ";
        cout<<"\n";
    }
    return 0;
}
/**

2 2 100
7 4
5 1

**/