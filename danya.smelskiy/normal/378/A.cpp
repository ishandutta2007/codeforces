#include <bits/stdc++.h>
using namespace std;
int n,m,first,draw,second,x,y;
int main(){
    cin>>n>>m;
    for (int i=1;i<=6;++i){
        x=abs(i-n);
        y=abs(i-m);
        if (x<y) ++first;
        else if (x>y) ++second;
        else ++draw;
    }
    cout<<first<<" "<<draw<<" "<<second;
}