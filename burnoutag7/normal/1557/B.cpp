#include<bits/stdc++.h>
using namespace std;

int n,k,a[100005];

void mian(){
    cin>>n>>k;
    vector<int> vx;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vx.emplace_back(a[i]);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    for(int i=1;i<=n;i++){
        a[i]=upper_bound(vx.begin(),vx.end(),a[i])-vx.begin();
        k-=i>1&&a[i]!=a[i-1]+1;
    }
    cout<<(k>0?"YES\n":"NO\n");
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