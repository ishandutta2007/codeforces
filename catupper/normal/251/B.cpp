#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> a,b,r,x;

int n,k,xx;

vector<int> change(vector<int> g){
  vector<int> res;
  for(int i = 0;i < n;i++)res.push_back(g[a[i]]);
  return res;
}



vector<int> egnahc(vector<int> g){
  vector<int> res;
  for(int i = 0;i < n;i++)res.push_back(g[r[i]]);
  return res;
}

vector<int> reverse(){
  vector<int> res;
  for(int i = 0;i < n;i++)res.push_back(i);
  for(int i = 0;i < n;i++)res[a[i]] = i;
  return res;
}

int main(){
  cin >> n >> k;
  for(int i = 0;i < n;i++){
    cin >> xx;
    a.push_back(xx-1);
  }
  r = reverse();
  for(int i = 0;i < n;i++){
    cin >> xx;
    b.push_back(xx-1);
  }
  for(int i = 0;i < n;i++)x.push_back(i);
  if(b == x){
    cout << "NO" << endl;
    return 0;
  }
  if(k != 1){
    if(change(x) == egnahc(x) && change(x) == b){
      cout<< "NO" << endl;
      return 0;
    }
  }
  for(int i = 1;i <= k;i++){
    x = change(x);
    if(x == b){
      if((k - i) % 2 == 0){
	cout << "YES" << endl;
	return 0;
      }
      break;
    }
  }
  x.clear();
  for(int i = 0;i < n;i++)x.push_back(i);
  for(int i = 1;i <= k;i++){
    x = egnahc(x);
    if(x == b){
      if((k - i) % 2 == 0){
	cout << "YES" << endl;
	return 0;
      }
      break;
    }
  }
  cout << "NO" << endl;
  return 0;
}