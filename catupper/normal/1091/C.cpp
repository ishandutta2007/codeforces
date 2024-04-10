#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
vector<Int> divisors, ans;
Int n;

int main(){
  cin >> n;
  for(Int i = 1;i*i <= n;i++){
    if(n % i)continue;
    divisors.push_back(i);
    if(n / i != i)divisors.push_back(n/i);
  }
  for(Int d: divisors){
      ans.push_back(n/d*(n-d)/2 + n/d);
  }
  sort(ans.begin(), ans.end());
  for(Int a: ans)cout << a << " ";
  cout << endl;
  return 0;
}