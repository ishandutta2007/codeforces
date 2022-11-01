#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,m;
ll a[20][20];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    {
        ll k;
        cin>>k;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>a[i][j];
            }
        }
        a[0][0]^=k;
    }
    ll ans=0;
    for(int i=0;i<=(n+m-2)/2;i++){
        int j=(n+m-2)/2-i;
        if(i<n&&j<m){
            map<ll,int> mp1,mp2;
            for(int s=0;s<1<<(n+m-2)/2;s++)if(__builtin_popcount(s)==i){
                ll sum=a[0][0];
                int x=0,y=0;
                for(int k=0;k<(n+m-2)/2;k++)if(s>>k&1){
                    x++;
                    sum^=a[x][y];
                }else{
                    y++;
                    sum^=a[x][y];
                }
                assert(x==i&&y==j);
                mp1[sum]++;
            }
            for(int s=0;s<1<<(n+m-1)/2;s++)if(__builtin_popcount(s)==n-1-i){
                ll sum=0;
                int x=i,y=j;
                for(int k=0;k<(n+m-1)/2;k++)if(s>>k&1){
                    x++;
                    sum^=a[x][y];
                }else{
                    y++;
                    sum^=a[x][y];
                }
                assert(x==n-1&&y==m-1);
                mp2[sum]++;
            }
            for(auto &p:mp1)ans+=(ll)p.second*mp2[p.first];
        }
    }
    cout<<ans;

    return 0;
}