#include <bits/stdc++.h>
using namespace std;




int n;
int x;
int c1,c2;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x;
        if (x==1) ++c1;
        else ++c2;
    }
    int res=0;
    int c=min(c2,c1);
    res=c;
    c1-=c;
    res+=c1/3;
    cout<<res;
}