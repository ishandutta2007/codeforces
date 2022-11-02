#include <bits/stdc++.h>
using namespace std;
constexpr int MAXN=1000;
pair<int,int> arr[MAXN];
int ans[MAXN];
int n;
bool resolve(){
    int ct=0;
    for(int i=0;i<n;++i){
        if((arr[i].first+arr[i].second)&1){
            ans[ct++]=i;
        }
    }
    if(ct==0||ct==n){
        if(ct==n){
            for(int i=0;i<n;++i){
                arr[i].second++;
            }
        }
        for(int i=0;i<n;++i){
            pair<int,int> tmp{(arr[i].first+arr[i].second)>>1,(arr[i].second-arr[i].first)>>1};
            arr[i]=tmp;
        }
        return false;
    }
    cout<<ct<<'\n';
    cout<<ans[0]+1;
    for(int i=1;i<ct;++i){
        cout<<' '<<ans[i]+1;
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>arr[i].first>>arr[i].second;
    }
    while(!resolve());
}