#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int n,a[100005],b[100005];
ll k;

void mian(){
    cin>>n>>k;
    k--;
    if(n-1<=59&&1ll<<n-1<=k){
        cout<<"-1\n";
        return;
    }
    iota(a+1,a+1+n,1);
    fill(b+1,b+1+n,0);
    for(int i=n;k>>n-i;i--){
        b[i]=k>>n-i&1;
    }
    for(int i=1,j;i<=n;i++)if(b[i+1]){
        int j=i+1;
        while(j<=n&&b[j])j++;
        j--;
        for(int k=0;i+k<j-k;k++)swap(a[i+k],a[j-k]);
        i=j;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<' ';
    cout<<'\n';
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