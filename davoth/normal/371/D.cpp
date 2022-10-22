#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int MAXN=2e5+10;
ll par[MAXN],sz[MAXN],wat[MAXN];
int gr(int x){
    if(par[x]==x) return x;
    par[x]=gr(par[x]);
    return par[x];
}
void mrg(int x, int y){
    int xp=gr(x),yp=gr(y);
    if(xp==yp) return;
    par[yp]=xp;
}
int main()
{
    fast_io;
    int n,m;
    cin >> n;
    for(int i=0; i<n; i++) cin >> sz[i+1];
    for(int i=0; i<=n; i++) par[i]=i;
    sz[0]=1e17;
    cin >> m;
    for(int i=0; i<m; i++){
        int q;
        cin >> q;
        if(q==2){
            int k;
            cin >> k;
            cout << wat[k] << '\n';
        }else{
            int pp,x;
            cin >> pp >> x;
            while(x>0){
                pp=gr(pp);
                if(wat[pp]+x<=sz[pp]) wat[pp]+=x,x=0;
                else{
                    x-=sz[pp]-wat[pp];
                    wat[pp]=sz[pp];
                    mrg(pp+1,pp);
                }
            }
        }
    }
    return 0;
}