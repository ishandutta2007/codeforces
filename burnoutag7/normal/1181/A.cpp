#include<bits/stdc++.h>
using namespace std;

long long x,y,z;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>x>>y>>z;
    cout<<(x+y)/z<<' ';
    long long lx=x%z,ly=y%z;
    if(lx+ly>=z){
        cout<<min(lx-(lx+ly-z),ly-(lx+ly-z));
    }else{
        cout<<0;
    }
    cout<<endl;

    return 0;
}