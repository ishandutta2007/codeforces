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


int zero = 0;
int one = 0;
string str;		  
int main(){
  cin >> str;
  for(int i = 0;i < str.size();i++){
    if(str[i] == '0'){
      cout << 1 << " " << zero + 1 << endl;
      zero++;
      zero %= 4;
    }
    else{
      cout << 3 << " " << one + 1 << endl;
      one += 2;
      one %= 4;
    }
  }
  return 0;
}