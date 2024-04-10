#include <bits/stdc++.h>
using namespace std;

int n,m;
map<int,int> kol;
int a[200005];
int b[200005];
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i){
        int x;
        cin>>x;
        ++kol[x];
    }
    cin>>m;
    for (int i=1;i<=m;++i)
        cin>>a[i];
    for (int i=1;i<=m;++i)
        cin>>b[i];
    int ans1=0,ans2=0,pos=1;
    for (int i=1;i<=m;++i) {
        int x,y;
        x=a[i];
        y=b[i];
        if (kol[x]>ans1 || (kol[x]==ans1 && kol[y]>ans2)) {
            ans1=kol[x];
            ans2=kol[y];
            pos=i;
        }
    }
    cout<<pos;
}