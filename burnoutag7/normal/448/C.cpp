#include<bits/stdc++.h>
using namespace std;

int n;
int a[5005];

int dfs(int l,int r,int cur){
    int mn=1e9;
    for(int i=l;i<=r;i++){
        mn=min(mn,a[i]);
    }
    int res=mn-cur;
    for(int i=l;i<=r;i++){
        if(a[i]>mn){
            int j=i;
            while(a[j+1]>mn)j++;
            res+=dfs(i,j,mn);
            i=j;
        }
    }
    return min(res,r-l+1);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<dfs(1,n,0)<<endl;

    return 0;
}