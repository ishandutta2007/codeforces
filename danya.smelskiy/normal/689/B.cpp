#include <bits/stdc++.h>
using namespace std;
int n;
int a[2000001];
int q[2000001];
int d[2000001];
bool used[2000001];


void bfs(){
    int l=1,r=1;
    q[1]=1;
    d[1]=0;
    used[1]=true;
    while (l<=r){
        int x=q[l];
        if (used[x+1]==false && x<n){
            ++r;
            q[r]=x+1;
            used[x+1]=true;
            d[x+1]=d[x]+1;
        }
        if (used[a[x]]==false){
            ++r;
            q[r]=a[x];
            used[a[x]]=true;
            d[a[x]]=d[x]+1;
        }
        if (used[x-1]==false && x>1){
            ++r;
            q[r]=x-1;
            used[x-1]=true;
            d[x-1]=d[x]+1;
        }
        ++l;
    }
}
int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    bfs();
    for (int i=1;i<=n;++i)
        cout<<d[i]<<" ";
}