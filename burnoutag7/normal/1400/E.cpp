#include<bits/stdc++.h>
using namespace std;

int n,a[5005];

long long dfs(int l,int r,int d){
    int mn=1e9;
    long long ver=0,hor=0;
    for(int i=l;i<=r;i++){
        if(a[i]-d){
            ver++;
        }
        mn=min(mn,a[i]);
    }
    if(ver==0)return 0;
    hor=mn-d;
    int nl=-1,nr;
    for(int i=l;i<=r;i++){
        if(a[i]-mn){
            if(nl==-1)nl=i;
            nr=i;
        }else{
            if(nl!=-1){
                hor+=dfs(nl,nr,mn);
                nl=-1;
            }
        }
    }
    if(nl!=-1){
        hor+=dfs(nl,nr,mn);
        nl=-1;
    }
    return min(ver,hor);
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<dfs(1,n,0)<<endl;

    return 0;
}