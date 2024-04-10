#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
typedef long long Int;
Int res = 40;
Int cnt2;
Int a, b, h, w, n, x;
vector<Int> vec;
Int f[108000];

Int dfs(Int x){
  if(x > res)return 40;
  if(h <= a && w <= b)return res = x;
  if(x == n){
    Int q = h / a + (h % a > 0);
    Int p = w / b + (w % b > 0);
    if(f[q] + f[p] <= cnt2)
      res = min(res, x + f[q] +  f[p]);
    return res;
  }
  if(h > a){
    a *= vec[x];
    res = min(res, dfs(x+1));
    a /= vec[x];
  }
  if(w > b){
    b *= vec[x];
    res = min(res, dfs(x+1));
    b /= vec[x];
  }
  return res;
}

int main(){
  cin >> h >> w >> a >> b >> n;
  for(Int i = 0;i < n;i++){
    cin >> x;
    vec.push_back(x);
  }
  for(Int i = 0;(1 << i) < 108000;i++){
    f[(1 << i)+1]++;
  }
  for(Int i = 1;i < 108000;i++){
    f[i] += f[i-1];
  }
  sort(vec.rbegin(), vec.rend());
  n = min(n, 22LL);
  for(Int i = 22;i < vec.size();i++){
    if(vec[i] == 2)cnt2++;
  }
  dfs(0);
  swap(h,w);
  dfs(0);
  if(res == 40)res = -1;
  cout << res << endl;
  return 0;
}