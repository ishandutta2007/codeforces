#include <bits/stdc++.h>
using namespace std;
long long n,x,y,up,down,d,u;
int main(){
    cin>>n;
    for (int i=1;i<=n;++i){
        cin>>x>>y;
        up+=x;
        down+=y;
        if (x%2==0 && y%2==1) ++d;
        else if (x%2==1 && y%2==0) ++u;
    }
    if (up%2==0 && down%2==0) cout<<"0";
    else if (up%2==1 && down%2==1 && (d>0 || u>0)) cout<<"1";
    else cout<<"-1";
}