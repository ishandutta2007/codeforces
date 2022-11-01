#include<bits/stdc++.h>
using namespace std;

const int inf=0x3f3f3f3f;
int n,m,a[255],b[255],f[255][255][255];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=b[i-1]+a[i];
    }
    memset(f,0x3f,sizeof(f));
    f[0][m][0]=0;
    int ans=inf;
    for(int i=1;i<=n;i++){
        for(int ps=m;ps>=0;ps--){
            int mn=inf;
            for(int h=i>1?ps/(i-1):m;h>=0;h--){
                mn=min(mn,f[i-1][h][ps]);
                f[i][h][ps+h]=min(f[i][h][ps+h],mn+abs(ps+h-b[i]));
                if(i==n&&ps+h==m)ans=min(ans,f[i][h][ps+h]);
            }
        }
    }
    cout<<ans<<'\n';

    return 0;
}