#include<bits/stdc++.h>
using namespace std;

int n,a[500005],p[500005];

void mian(){
    cin>>n;
    vector<int> vx;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        vx.emplace_back(a[i]);
    }
    sort(vx.begin(),vx.end());
    vx.erase(unique(vx.begin(),vx.end()),vx.end());
    if(vx.size()<n){
        cout<<"YES\n";
        return;
    }
    for(int i=1;i<=n;i++){
        a[i]=upper_bound(vx.begin(),vx.end(),a[i])-vx.begin();
        p[a[i]]=i;
    }
    for(int i=1;i<=n-2;i++)if(a[i]!=i){
        int c=p[i],d=i,d1=i+1==p[i]?i+2:i+1;
        p[a[c]]=d;
        p[a[d]]=c;
        swap(a[c],a[d]);
        p[a[c]]=d1;
        p[a[d1]]=c;
        swap(a[c],a[d1]);
    }
    cout<<(a[n]==n?"YES\n":"NO\n");
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