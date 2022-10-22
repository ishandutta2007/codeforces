#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int N;
    cin>>N;
    long long int tot=0;
    for(int i=2;i<N;i++){
      tot+=i*(i+1);
    }
    cout<<tot;
  return 0;
}