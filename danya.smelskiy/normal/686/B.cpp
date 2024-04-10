#include <bits/stdc++.h>
using namespace std;


int n;
int a[105];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        for (int j=i;j>1;--j)
        if (a[j]<a[j-1]) {
            cout<<j-1<<" "<<j<<'\n';
            swap(a[j],a[j-1]);
        } else break;
    }
}