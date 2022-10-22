#include<iostream>
#include<algorithm>

using namespace std;
typedef long long Int;
bool water = false;
Int stamina;
Int ground2, swim2;
Int res, l[216000];
char c;
Int n;
int main(){
  cin >> n;
  for(Int i = 0;i < n;i++)cin >> l[i];
  for(Int i = 0;i < n;i++){
    cin >> c;
    if(c == 'W'){
      water = true;
      res += l[i] * 3;
      swim2 += l[i] * 2;
      stamina += l[i];
    }
    if(c == 'G'){
      res += l[i] * 5;
      ground2 += l[i] * 2;
      stamina += l[i];
    }
    if(c == 'L'){
      if(stamina < l[i]){
	Int need = l[i] - stamina;
	if(water)res += need * 3;
	else res += need * 5;
	stamina += need;
      }
      stamina -= l[i];
      res += l[i];
    }
    ground2 = min(ground2, stamina);
  }
  res -= ground2 * 2;
  res -= stamina - ground2;
  cout << res << endl;
  return 0;
}