#include<bits/stdc++.h>
using namespace std;
int T,n;
void solve(){
    scanf("%d",&n);
    vector<int> v;
    while(n>0) v.push_back(n%10),n/=10;
    if(v.size()==2){
        printf("%d\n",v[0]);
        return;
    }else{
        int minn=10;
        for(auto x:v) minn=min(minn,x);
        printf("%d\n",minn);
    }
}
int main(){
    scanf("%d",&T);
    while(T--) solve();
    return 0;
}