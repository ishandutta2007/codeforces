#include<bits/stdc++.h>
using namespace std;

int l,r,a[200005][25];

void mian(){
    cin>>l>>r;
    int ans=r-l;
    for(int i=0;i<20;i++)ans=min(ans,r-l+1-(a[r][i]-a[l-1][i]));
    cout<<ans<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i=1;i<=200000;i++){
        for(int j=0;j<20;j++)a[i][j]=a[i-1][j]+(i>>j&1);
    }

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}