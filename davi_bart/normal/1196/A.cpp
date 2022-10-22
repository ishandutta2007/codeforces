#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--){
      ll a,b,c;
      cin>>a>>b>>c;
      cout<<(a+b+c)/2<<endl;
    }
    return 0;
}