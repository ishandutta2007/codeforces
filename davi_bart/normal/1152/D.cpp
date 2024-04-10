#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
int N;
long long int memo[1001][1001];
long long int sol(int aperte,int chiuse,bool preso){
  if(memo[aperte][chiuse]>0)return memo[aperte][chiuse];
  if(aperte<N)memo[aperte][chiuse]+=sol(aperte+1,chiuse,!preso);
  if(chiuse<aperte)memo[aperte][chiuse]+=sol(aperte,chiuse+1,!preso);
  memo[aperte][chiuse]+=preso;
  return memo[aperte][chiuse]%1000000007;

}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>N;
    cout<<sol(0,0,0);
    return 0;
}