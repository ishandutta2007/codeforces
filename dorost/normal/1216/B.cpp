#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	int n,d = 0;
  	cin >> n;
  	int a[n] , b[n];
  	for(int i = 0; i < n; i++){
  	  cin >> a[i];
  	  b[i] = a[i];
 	 }
  sort(a, a + n);
  reverse(a, a + n);
  for(int i = 0; i < n; i++){
    d += (a[i] * i) + 1;
  }
  cout << d << endl;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(a[i] == b[j]){
        b[j]=0;
        cout << j + 1 << ' ';
        j = j + n + 1;
        break;
      }
    }
  }
}