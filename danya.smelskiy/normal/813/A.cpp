#include <bits/stdc++.h>
using namespace std;

long long sum,n,m,a[100001],x,y;

int main(){
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        sum+=a[i];
    cin>>m;
    for (int i=1;i<=m;++i){
        cin>>x>>y;
        if (x<=sum && y>=sum) {
            cout<<sum;
            return 0;
        }
        if (x>sum) {
            cout<<x;
            return 0;
        }
    }
    cout<<"-1";
}