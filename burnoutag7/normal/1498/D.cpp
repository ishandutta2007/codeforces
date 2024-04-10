#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m,typ[205],qy[205],f[100005];
ll qx[205];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>typ[i]>>qx[i]>>qy[i];
    }
    memset(f,-1,sizeof(f));
    f[0]=0;
    for(int i=0;i<=n;i++){
        for(int j=m;j>=0;j--)if(f[j]!=-1){
            ll nj=j;
            for(int k=1;k<=qy[i];k++){
                nj=typ[i]==1?nj+(qx[i]+99999)/100000:(nj*qx[i]+99999)/100000;
                if(nj<=m&&f[nj]==-1){
                    f[nj]=i+1;
                }else break;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<f[i]<<' ';
    }

    return 0;
}