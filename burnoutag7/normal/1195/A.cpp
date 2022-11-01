#include<bits/stdc++.h>
using namespace std;

int n,k,l;
int a[1005];
int cnt[1005];
int mx;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;l=(n+1)/2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=k;i++){
        l-=cnt[i]/2;
        mx+=cnt[i]/2*2;
        cnt[i]%=2;
    }
    for(int i=1;i<=k;i++){
        if(l<=0)break;
        if(cnt[i]){
            l--;
            mx++;
        }
    }
    cout<<mx<<endl;

    return 0;
}