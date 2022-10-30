#include <bits/stdc++.h>
using namespace std;


long long x,y,xx,yy;

int main(){
    cin>>x>>y;
    cin>>xx>>yy;
    for (int i=max(y,yy);i<=1000000;++i){
           if ((i-y)%x==0 && (i-yy)%xx==0) {
            cout<<i;
            return 0;
           }
    }
    cout<<-1;
}