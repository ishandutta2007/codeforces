#include<set>
#include<map>
#include<algorithm>
#include<iostream>

using namespace std;
typedef long long Int;
Int q, x, u, v, w;
map<Int, Int> sum;
int main(){
  cin >> q;
  while(q--){
    cin >> x;
    if(x == 1){
      cin >> u >> v >> w;
      while(u != v){
	if(u < v)swap(u, v);
	sum[u] += w;
	u /= 2;
      }
    }
    else{
      cin >> u >> v;
      Int res = 0;
      while(u != v){
	if(u < v)swap(u, v);
	res += sum[u];
	u /= 2;
      }
      cout << res << endl;
    }
  }
}