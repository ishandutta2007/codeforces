#include<bits/stdc++.h>
using namespace std;

int n,k,a[105],cnt;

void mian(){
    cin>>n>>k;
    int cnt=0;
    a[0]=-1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i]!=a[i-1];
    }
    if(k==1&&cnt>1)cout<<"-1\n";
    else cout<<(cnt<=k?1:1+(cnt-2)/(k-1))<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}