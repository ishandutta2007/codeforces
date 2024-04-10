#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000007
typedef long long Int;
typedef vector<vector<Int> > Mat;



Mat mult(Mat a, Mat b){
  Int n = a.size();
  Mat res;
  vector<Int> hoge;
  for(Int i = 0;i < n;i++){
    hoge.clear();
    for(Int j = 0;j < n;j++){
      hoge.push_back(0);
    }
    res.push_back(hoge);
  }
  for(Int i = 0;i < n;i++){
    for(Int j = 0;j < n;j++){
      for(Int k = 0;k < n;k++){
	res[i][k] += a[i][j] * b[j][k];
	res[i][k] %= MOD;
      }
    }
  }
  return res;
}

void view(Mat x){
  Int n = x.size();
  for(Int i = 0;i < n;i++){
    for(Int j = 0;j < n;j++){
      cout << x[i][j] << " ";
    }cout << endl;
  }cout << endl;
}

Mat one;


Mat mpow(Mat a, Int p){
  if(p == 0)return one;
  Mat res = mpow(a, p / 2);
  res = mult(res, res);
  if(p % 2)res = mult(res, a);
  return res;
}

Int pow(Int x, Int p){
  if(p == 0)return 1;
  Int res = pow(x, p / 2);
  res *= res;res %= MOD;
  if(p % 2)res *= x;
  return res % MOD;
}

int main(){
  Mat hoge;
  vector<Int> tmp;
  for(Int i = 0;i < 3;i++)tmp.push_back(0);
  for(Int i = 0;i < 3;i++)hoge.push_back(tmp), one.push_back(tmp);
  for(Int i = 0;i < 3;i++){
    for(Int j = 0;j < 3;j++){
      one[i][j] = i == j;
      if(i + j == 2)continue;
      hoge[i][j] = 1;
    }
  }
  Int n;
  Int a, k;
  Int t;
  Int pp = 2;
  cin >> t;
  Int even = 1;
  for(Int i = 0;i < t;i++){
    cin >> k;
    even *= k;even %= 2;
    pp = pow(pp, k);
  }
  Int res = pp;
  if(even)res += MOD -2;
  else res += 2;
  while(res % 6)res += MOD;
  while(pp % 2)pp += MOD;
  res /= 6;
  res %= MOD;
  pp /= 2;
  pp %= MOD;
  cout << res << "/" << pp << endl;
  return 0;  
}