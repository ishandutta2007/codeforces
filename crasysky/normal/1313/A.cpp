#include <bits/stdc++.h>
using namespace std;

int main(){
    int T; cin>>T;
    while (T--){
        int a,b,c; cin>>a>>b>>c;
        int ans=0;
        if (a) --a,++ans;
        if (b) --b,++ans;
        if (c) --c,++ans;
        int x=max(a,max(b,c)),z=min(a,min(b,c)),y=a+b+c-x-z;
        if (z&&x) --z,--x,++ans;
        if (z&&y) --z,--y,++ans;
        if (x&&y) --x,--y,++ans;
        if (x&&y&&z) ++ans;
        cout<<ans<<endl;
    }
}