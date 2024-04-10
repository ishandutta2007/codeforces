#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int first[n+1];
  int second[n+1];
  bool found[n+1];
  for(int i = 1; i<n+1; i++){
    found[i] = false;
  }
  for(int i = 0; i<2*n; i++){
    int temp;
    cin >> temp;
    if(found[temp] == false){
      first[temp] = i;
      found[temp] = true;
    }
    else second[temp] = i;
  }
  int cs = 0;
  int cd = 0;
  long long sum = 0;
  for(int i = 1; i<=n; i++){
    int csum = INT_MAX;
    int tempf = first[i];
    int temps = second[i];
    int ccs = cs;
    int ccd = cd;
    if(abs(tempf - ccs) + abs(temps - ccd) < csum){
      csum = abs(tempf - ccs) + abs(temps - ccd);
      cs = tempf;
      cd = temps;
    }
    if(abs(temps - ccs) + abs(tempf - ccd) < csum){
      csum = abs(temps - ccs) + abs(tempf - ccd);
      cs = temps;
      cd = tempf;
    }
    sum += csum;
  }

  cout << sum << endl;
}