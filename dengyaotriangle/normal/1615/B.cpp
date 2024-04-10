#include<bits/stdc++.h>
using namespace std;
//dengyaotriangle!

const int maxn=200005;
const int maxl=20;
int s[maxl][maxn];

int main(){
    for(int i=0;i<maxl;i++){
        for(int j=1;j<maxn;j++)s[i][j]=s[i][j-1]+((j>>i)&1);
    }
    ios::sync_with_stdio(0);cin.tie(0);
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int ans=r-l+1;
        for(int i=0;i<maxl;i++)ans=min(ans,r-l+1-s[i][r]+s[i][l-1]);
        cout<<ans<<'\n';
    }
    return 0;
}