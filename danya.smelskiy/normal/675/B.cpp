#include <bits/stdc++.h>
using namespace std;

long long ans,n;
int a,b,c,d;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>a>>b>>c>>d;
    for (int i=1;i<=n;++i) {
        int x=i;
        int y=b+x-c;
        int xx=a+x-d;
        int yy=b+xx-c;
        if (x>0 && y>0 && xx>0 && yy>0 && x<=n && y<=n && xx<=n && yy<=n) ans+=n;
    }
    cout<<ans;
}