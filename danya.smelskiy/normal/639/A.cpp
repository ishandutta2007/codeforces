#include <bits/stdc++.h>
using namespace std;
int n,k,m;
int a[2000001];
int b[10000];
bool used[2000001];
int x,y;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>m;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    int last=0;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (x==2){
            if (used[y]==false || (last==k && a[y]<b[k])) cout<<"NO";
            else cout<<"YES";
            cout<<'\n';
        } else {
            used[y]=true;
            if (last==k && a[y]<b[k]) continue;
            if (last==k) b[last]=a[y];
            else {
                ++last;
                b[last]=a[y];
            }
            sort(b+1,b+last+1,cmp);
        }
    }
}