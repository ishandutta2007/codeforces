#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int dr[]={-1,0,1,0};
int dc[]={0,1,0,-1};

const int N=50+5;
int n,m;
int v[N][N];
int p[4],viz[4];
int r,c;
int rf,cf;
string a;

bool valid(int r,int c) {
    if(1<=r && 1<=c && r<=n && c<=m) {
        return 1;
    }
    return 0;
}

char f(int x) {
    if(x==0) return 'U';
    if(x==1) return 'R';
    if(x==2) return 'D';
    if(x==3) return 'L';
}

int ans=0;

void bkt(int strat) {
    if(strat==4) {
        int rx=r;
        int cx=c;
        bool is=0;
        if(f(p[0])=='D' && f(p[1])=='L') is=1;
        for(auto itr:a) {
            rx+=dr[p[itr-'0']];
            cx+=dc[p[itr-'0']];
            if(rx==rf && cx==cf) {
                ans++;
                return;
            }
            if(valid(rx,cx)==0 || v[rx][cx]==1) {
                return;
            }
        }
        return;
    }
    for(int i=0;i<4;i++) {
        if(viz[i]==0) {
            viz[i]=1;
            p[strat]=i;
            bkt(strat+1);
            viz[i]=0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        string a;
        cin>>a;
        for(int j=1;j<=m;j++) {
            if(a[j-1]=='S') {
                r=i;
                c=j;
            }
            if(a[j-1]=='E') {
                rf=i;
                cf=j;
            }
            if(a[j-1]=='#') {
                v[i][j]=1;
            }
        }
    }
    cin>>a;
    bkt(0);
    cout<<ans<<"\n";
    return 0;
}
/**


**/