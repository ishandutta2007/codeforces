#include<bits/stdc++.h>
using namespace std;

int n,x,a[505],cnt,ans;

void mian(){
    cin>>n>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cnt=0;ans=1e9;
    for(int i=1;i<=n;i++){
        if(is_sorted(a+1,a+1+n))ans=min(ans,cnt);
        if(a[i]>x){
            swap(a[i],x);
            cnt++;
        }
    }
    if(ans==1e9)ans=-1;
    cout<<ans<<'\n';
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