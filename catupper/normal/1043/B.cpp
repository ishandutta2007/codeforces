#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

vector<Int> ans;
vector<Int> a;

void view(vector<Int> x){
  for(int a: x)cout << a << " " ;cout << endl;
  return;
}

Int n;
bool ok(int k){
  vector<Int> x;
  vector<Int> a2;
  for(int i = 0;i < k;i++){
    if(i == 0)x.push_back(a[i]);
    else x.push_back(a[i] - a[i-1]);
  }
  a2.push_back(x[0]);
  for(int i = 1;i < n;i++){
    a2.push_back(a2[i-1] + x[i % k]);
  }
  return a2 == a;
}

int main(){
  cin >> n;
  for(int i = 0;i < n;i++){
    int x;cin >> x;
    a.push_back(x);
  }
  for(int k = 1;k <= n;k++){
    if(ok(k))ans.push_back(k);
  }
  cout << ans.size() << endl;
  for(int a: ans)cout << a << " ";cout << endl;
  return 0;
}