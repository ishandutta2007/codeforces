#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
template<typename T>
int sz(const T &a){return (int)a.size();}
lli ans[400];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    lli u,v;
    cin>>u>>v;
    if(u>v){
        printf("-1\n");
        return 0;
    }
    lli o=1;
    map<lli,int> arr;
    int maxbit=0;
    for(lli i=0;i<62;i++){
        if(u&(o<<i)){
            arr[o<<i]++;
            maxbit=i;
        }
    }
    lli diff=v-u;
    for(lli i=61;i>=1;i--){
        if(diff&(o<<i)){
            arr[o<<(i-1)]++;
            arr[o<<(i-1)]++;
            diff-=(o<<i);
        }
    }
    if(diff){
        printf("-1\n");
        return 0;
    }
    int la=0;
    for(auto x:arr){
        la=max(la,x.second);
        for(int i=0;i<x.second;i++){
            ans[i]+=x.first;
        }
    }
    printf("%d\n",la);
    for(int i=0;i<la;i++)printf("%lli ",ans[i]);
    return 0;
}