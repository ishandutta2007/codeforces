#include <bits/stdc++.h>
using namespace std;

int n;
int ans;


int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        for (int j=i-1;j>0;--j) {
            int x=(i^j);
            if (x<=j && x+i>j && x+j>i && i+j>x) ++ans;
        }
    }
    cout<<ans;
}