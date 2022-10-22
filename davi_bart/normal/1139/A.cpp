#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <cmath>
#include <math.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    long long int tot=0;
    for(int i=1;i<=N;i++){
      char a;
      cin>>a;
      int o=a-'0';
      if(o%2==0)tot+=i;
    }
    cout<<tot;
    return 0;
}