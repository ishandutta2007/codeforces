#include<bits/stdc++.h>
using namespace std;

int n,sz,ans;
char s[200005];
int col[200005];
int mx[200005];

int qry(int val){
    int l=1,r=n,m,res;
    while(l<=r){
        m=(l+r)>>1;
        if(mx[m]<=val){
            res=m;
            r=m-1;
        }else{
            l=m+1;
        }
    }
    return res;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    sz=1;while(sz<n)sz<<=1;
    cin>>s+1;
    for(int i=1;i<=n;i++){
        int pos=qry(s[i]);
        mx[pos]=s[i];
        col[i]=pos;
        ans=max(ans,pos);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)cout<<col[i]<<' ';
    cout<<endl;

    return 0;
}