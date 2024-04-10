#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;

Int cnt[540000];
Int n;

Int check(Int x){
  cnt[x]++;
  Int ind = 0;
  vector<Int> dig;
  vector<Int> sum(n+1, 0);
  vector<Int> rmincnt(n+2, 0);
  vector<Int> rhs(n+1, 0);
  for(Int i = n;i >= 0;i--)
    for(Int j = 0;j < cnt[i];j++)
      dig.push_back(i);
  cnt[x]--;
  
  for(Int i = 0;i <= n;i++){
    if(i)sum[i] = sum[i-1];
    sum[i] += dig[i];
  }
  Int rsum = 0;
  for(Int i = n;i >= 0;i--){
    rhs[i] = i * (i+1) + rsum;
    rmincnt[min(i,dig[i])]++;
    rsum += min(i, dig[i]);
    rsum -= rmincnt[i+1];
    rmincnt[i] += rmincnt[i+1];
  }
  //  cout << x << endl;
  for(Int i = 0;i <= n;i++){
    //    cout << sum[i] << " " << rhs[i] << " " << dig[i] << " "<< x << " " << (dig[i] < x) << endl;
    if(sum[i] <= rhs[i])continue;
    if(dig[i] <= x)return 1;
    else return -1;
  }
  return 0;    
}

int main(){
  cin >> n;
  Int parity = 0;
  for(Int i = 0;i < n;i++){
    Int dig;
    cin >> dig;
    cnt[dig]++;
    parity ^= dig % 2;
  }
  Int bottom = 0, top = n / 2;
  while(top - bottom > 1){
    Int mid = (top + bottom) / 2;
    if(check(mid*2+parity) == -1)bottom = mid;
    else top = mid;
  }
  Int l = top;
  if(check(parity) == 0)l = 0;

  bottom = 0, top = n / 2;
  while(top - bottom > 1){
    Int mid = (top + bottom) / 2;
    if(check(mid*2+parity) == 1)top = mid;
    else bottom = mid;
  }
  Int r = bottom;
  if(n/2*2+parity <= n && check(n/2*2+parity) == 0)r = n/2;
  if(r < l){
    cout << -1 << endl;
  }
  else{
    for(Int i = l;i <= r;i++){
      cout << i * 2 + parity << " ";
    }cout << endl;
  }
  return 0;
}