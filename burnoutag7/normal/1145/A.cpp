#include<bits/stdc++.h>
using namespace std;

int n,a[16];

int dfs(int l,int r){
    bool f=true;
    for(int i=l+1;i<r;i++){
        if(a[i]<a[i-1])f=false;
    }
    if(f)return r-l;
    return max(dfs(l,(l+r)>>1),dfs((l+r)>>1,r));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<dfs(0,n)<<endl;

    return 0;
}