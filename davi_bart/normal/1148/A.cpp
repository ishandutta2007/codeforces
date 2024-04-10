#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int main(){
  //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int tot=2*c;
    if(a==b)tot+=2*a;
    else tot+=2*min(a,b)+1;
    cout<<tot;

    return 0;
}