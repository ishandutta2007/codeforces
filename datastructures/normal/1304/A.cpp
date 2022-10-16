#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#define int long long
using namespace std;
int t,x,y,a,b;
signed main(){
    cin>>t;
    while(t--){
        cin>>x>>y>>a>>b;
        if ((y-x)%(a+b)!=0)cout<<-1<<endl;
        else cout<<(y-x)/(a+b)<<endl;
    }
    return 0;
}