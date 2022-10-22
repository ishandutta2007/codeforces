#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long Int;
#define div div_____
Int n, m;
bool no[216000];

bool prime[216000];
Int x;
Int before[216000];
Int meb[216000];

vector<Int> div[216000];
vector<Int> nums[216000];
Int cnt[216000];

Int pow(Int x, Int n, Int m){
  if(n == 0)return 1;
  Int res = pow(x, n / 2, m);
  res *= res;res %= m;
  if(n % 2)res *= x;
  return res % m;
}

Int gcd(Int a, Int b){
  if(a == 0)return b;
  return gcd(b % a, a); 
}

Int inv(Int x, Int m){
  return pow(x, meb[m] - 1, m);
}

void init(){
  fill(prime, prime + 216000, true);
  fill(meb, meb + 216000, 1);
  prime[0] = prime[1] = false;
  for(Int i = 2;i * i < 216000;i++){
    if(!prime[i])continue;
    for(Int j = i * i;j < 216000;j+=i){
      prime[j] = false;
    }
  }

  for(Int i = 1;i < 216000;i++){
    if(!prime[i])continue;
    for(Int p = i;p < 216000;p *= i){
      for(Int j = p;j < 216000;j += p){
	if(p == i)meb[j] *= i-1;
	else meb[j] *= i;
      }
    }
    
  }
}
int main(){
  init();
  
  cin >> n >> m;
  for(Int i = 0;i < n;i++){
    cin >> x;
    no[x] = true;
  }

  for(Int i = 0;i < m;i++){
    if(no[i])continue;
    Int g = gcd(m, i);
    nums[g].push_back(i);
  }

  for(Int i = 0;i < m;i++){
    cnt[i] = nums[i].size();
  }
  
  for(Int i = 1;i < m;i++){
    for(Int j = 0;j < m;j += i){
      div[j].push_back(i);
    }
  }
  
  Int now = 0;
  for(Int i = 2;i < m;i++){
    Int tmp = 0;
    for(Int j = 0;j < div[i].size();j++){
      Int d = div[i][j];
      if(d == i)continue;
      if(tmp < cnt[d]){
	before[i] = d;
	tmp = cnt[d];
      }
    }
    cnt[i] += tmp;
    if(cnt[i] > cnt[now])now = i;
  }

  vector<Int> res;
  if(!no[0])res.push_back(0);
  for(Int i = now;i;i = before[i]){
    for(Int j = 0;j < nums[i].size();j++){
      res.push_back(nums[i][j]);
    }
  }

  for(Int i = 0;i < res.size();i++){
    Int op = res.size() - i - 1;
    if(i < op)swap(res[i], res[op]);
  }

  cout << res.size() << endl;
  cout << res[0];
  for(Int i = 1;i < res.size();i++){
    
    Int x = res[i-1];
    Int y = res[i];
    Int g = gcd(m, x);
    x /= g;

    cout << " " <<  (y / g * inv(x, m / g)) % m;
 
  }cout << endl;
  return 0;
  
  
}