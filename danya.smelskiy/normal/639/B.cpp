#include <bits/stdc++.h>
using namespace std;

int n,d,h,last;

int main(){
    cin>>n>>d>>h;
    if (h*2<d || d>n-1 || (d==1 && n>2) || h>n-1){
        cout<<"-1";
        return 0;
    }
    last=1;
    for (int i=1;i<=h;++i){
        ++last;
        cout<<last-1<<" "<<last<<'\n';
    }
    d-=h;
    if (d>0){
        ++last;
        cout<<1<<" "<<last<<'\n';
        d--;
    }
    for (int i=1;i<=d;++i){
        ++last;
        cout<<last-1<<" "<<last<<'\n';
    }
    if (d==0) {
        for (int i=last+1;i<=n;++i)
            if (h==1) cout<<1<<" "<<i<<'\n'; else
            cout<<h<<" "<<i<<'\n';
    } else
    for (int i=last+1;i<=n;++i){
        cout<<1<<" "<<i<<'\n';
    }
}