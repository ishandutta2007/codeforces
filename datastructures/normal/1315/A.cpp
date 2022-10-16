#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t,a,b,x,y;
signed main(){
    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;
        cout<<max(max(a*y,(x-a-1)*y),max(b*x,(y-b-1)*x))<<endl;
    }
    return 0;
}