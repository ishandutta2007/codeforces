#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 105;
 ll n, m, t, v[N][N], b[N][N], a[N][N];
 bool vis[N][N];
 struct node {
    int x, y;
    ll z;
 }mi[10005];
 bool cmp(node k, node l) {
    return k.z<l.z;
 }
int main(){
    cin>>t;
    while(t--) {
        cin>>n>>m;
        ll cnt=0;
        ll q=0;
        memset(mi, 0, sizeof mi);
        memset(v, 0, sizeof v);
        memset(vis, 0, sizeof vis);
        memset(a, 0, sizeof a);
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                    cin>>mi[++cnt].z;
                    mi[cnt].x=i;
                    mi[cnt].y=j;
                    b[i][j]=mi[cnt].z;
            }
        }
        sort(mi+1, mi+1+cnt, cmp);
        for(int i=1; i<=m; i++) {
            a[mi[i].x][i]=mi[i].z;
            vis[mi[i].x][mi[i].y]=1;//
        }
        for(int i=1; i<=n; i++) {
            q=0;
            for(int j=1; j<=m; j++) {//
                if(!vis[i][j]) v[i][++q]=b[i][j];
            }
        }
        for(int i=1; i<=n; i++) {
            q=0;
            for(int j=1; j<=m; j++) {
                if(!a[i][j]) a[i][j]=v[i][++q];
            }
        }
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                    cout<<a[i][j]<<" \n"[j==m];
            }
        }
    }
    return 0;
}