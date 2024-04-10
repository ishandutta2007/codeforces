#include <bits/stdc++.h>
using namespace std;
int n;
long long ans;
long long tree[200000];
int main(){
    cin>>n;
    long long sz=1;
    for (int i=0;i<=n;++i)
        sz*=2;
    sz--;
    for (int i=2;i<=sz;++i)
        cin>>tree[i];
    for (int i=sz;i>=1;--i){
        ans+=max(tree[i+i],tree[i+i+1])-min(tree[i+i],tree[i+i+1]);
        tree[i]+=max(tree[i+i],tree[i+i+1]);
    }
    cout<<ans;
}