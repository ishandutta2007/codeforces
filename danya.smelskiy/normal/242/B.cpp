#include<bits/stdc++.h>
using namespace std;

int n;
pair<int,int> a[100005];
int l=1e9;
int r=-1e9;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i].first>>a[i].second;
        l=min(l,a[i].first); r=max(r,a[i].second);
    }
    for (int i=1;i<=n;++i)
    if (a[i].first==l && a[i].second==r) {
        cout<<i;
        return 0;
    }
    cout<<"-1";
}