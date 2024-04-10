#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;

int n,k;
bool ok;
int v[maxn];

void mrg(int l,int r){
    if(k<2)return;
    if(l+1==r) return;
    k-=2;
    int mid=(l+r)>>1;
    swap(v[mid],v[mid+1]);
    mrg(l,mid);
    mrg(mid,r);
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)v[i]=i;
    k--;
    mrg(0,n);
    if(k==0){
        for(int i=1;i<=n;i++)cout<<v[i]<<' ';
    }else cout<<-1;
    return 0;
}