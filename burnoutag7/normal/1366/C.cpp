#include<bits/stdc++.h>
using namespace std;

int n,m;
int a[35][35];
int cnt[65],tot[65];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--){
        cin>>n>>m;
        memset(tot,0,sizeof(tot));
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
                tot[min(i+j,n+m-i-j-2)]++;
                cnt[min(i+j,n+m-i-j-2)]+=a[i][j];
            }
        }
        int ans=0;
        for(int i=0;i<n+m-1>>1;i++){
            ans+=min(cnt[i],tot[i]-cnt[i]);
        }
        cout<<ans<<endl;
    }

    return 0;
}