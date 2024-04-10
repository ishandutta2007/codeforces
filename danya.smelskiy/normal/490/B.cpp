#include <bits/stdc++.h>
using namespace std;

int n;
int b[1000001];
bool used[1000001];
pair<int,int> a[1000001];
int y[1000001],f;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>a[i].first>>a[i].second;
        y[a[i].first]=a[i].second;
        used[a[i].second]=true;
    }
    for (int i=1;i<=n;++i)
    if (used[a[i].first]==false){
        f=a[i].first;
        break;
    }
    b[1]=f;
    b[2]=y[0];
    for (int i=3;i<=n;++i){
        b[i]=y[b[i-2]];
    }
    for (int i=1;i<=n;++i)
        cout<<b[i]<<" ";
}