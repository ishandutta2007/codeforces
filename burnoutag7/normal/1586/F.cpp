#include<bits/stdc++.h>
using namespace std;

int n,k,e[1005][1005],ans;

void sol(int l,int r,int c){
    int len=(r-l+1+k-1)/k;
    ans=max(ans,c);
    if(len==1){
        for(int i=l;i<r;i++)for(int j=i+1;j<=r;j++)e[i][j]=c;
    }else{
        for(int st=l;st<=r;st+=len){
            if(st+len<=r)for(int i=st;i<st+len;i++)for(int j=st+len;j<=r;j++)e[i][j]=c;
            sol(st,min(st+len-1,r),c+1);
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    sol(1,n,1);
    cout<<ans<<'\n';
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            cout<<e[i][j]<<' ';
        }
    }

    return 0;
}