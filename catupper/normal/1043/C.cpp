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
Int swp[2][216000];
Int n;
string str;
string rev(string a){
  string res = "";
  for(int i = 0;i < a.size();i++)res += a[a.size() - i - 1];
  return res;
}
string ml = "", mr = "";
int main(){
  cin >> str;
  int n = str.size();
  for(int i = 0;i < str.size();i++){
    string a0 = ml + str[i];
    string a1= str[i] + rev(mr);
    string b0 = mr + str[i];
    string b1 = str[i] + rev(ml);
    if(a0 <= a1)ml = a0;
    else{
      ml = a1;
      swp[0][i] = true;
    }
    
    if(rev(b0) <= rev(b1))mr = b0;
    else{
      mr = b1;
      swp[1][i] = true;
    }
    //    cout << ml << " " << mr << endl;
  }
  str = "";
  int now = 0;
  for(int i = n-1;i >= 0;i--){
    if(swp[now][i]){
      str += "1";
      now ^= 1;
    }
    else{
      str += "0";
    }
  }
  for(char c:rev(str)){
    cout << c << " ";
  }cout << endl;
  return 0;
}