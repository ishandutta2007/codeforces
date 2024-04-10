#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int step[2160000];
int sum[2160000];
string str;
int sm;
int cnt[216000];
void printit(int x){
  string str;
  while(x){
	str += (char)('0' + x % 10);
	x /= 10;
  }
  for(int i = str.size() - 1;i >= 0;i--){
	cout << str[i];
	if(i)cout << "+";
  }
  cout << endl;
}


int main(){
  int n;
  for(int i = 1;i < 2000000;i++){
	sum[i] = i % 10 + sum[i / 10];
	step[i] = 1 + step[sum[i]];
	if(i < 10)step[i] = 0;
  }

  cin >> n;
  cin >> str;
  for(int i = 0;i < n;i++){
	sm += str[i] - '0';
	cnt[str[i] - '0']++;
  }
  int mx, mxcnt = 0;
  for(int i = 1;i < 10;i++){
	if(mxcnt < cnt[i]){
	  mxcnt = cnt[i];
	  mx = i;
	}
  }
  int res = 0;
  while(step[sm + mx * 9 * res] > 2)res++;
  int nx = sm + mx * 9 * res;
  int ng = 0;
  for(int i = 0;i < n;i++){
	cout << str[i];
	if(str[i] - '0' == mx && res && ng <= 0){
	  res--;
	  ng = 1;
	  continue;
	}
	else{
	  if(i != n-1)cout << "+";
	  ng--;
	}
  }
  cout << endl;
  printit(nx);
  nx = sum[nx];
  printit(nx);
  return 0;  
}