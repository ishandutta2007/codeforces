#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;
  for(int j = 0; j<q; j++){
    int n, k;
    cin >> n >> k;
    string given;
    string temp = "RGB";
    cin >> given;
    int dpr[n];
    int dpg[n];
    int dpb[n];
    memset(dpr, 0, n*sizeof(dpr[0]));
    memset(dpg, 0, n*sizeof(dpr[0]));
    memset(dpb, 0, n*sizeof(dpr[0]));
    int cr = 0, cg = 1, cb = 2;
    int mi = INT_MAX;
    for(int i = 0; i<k; i++){
      if(given[i] != temp[cr]) ++dpr[k-1]; 
      if(given[i] != temp[cg]) ++dpg[k-1]; 
      if(given[i] != temp[cb]) ++dpb[k-1];
      if(i == k-1) break;
      ++cr;
      ++cg;
      ++cb;
      cr %= 3;
      cg %= 3;
      cb %= 3; 
    }
    mi = min(mi, dpr[k-1]);
    mi = min(mi, dpg[k-1]);
    mi = min(mi, dpb[k-1]);
    for(int i = k; i<n; i++){
      dpr[i] = dpb[i-1];
      dpg[i] = dpr[i-1];
      dpb[i] = dpg[i-1];
      if(temp[cr] != given[i]) ++dpr[i];
      if(temp[cg] != given[i]) ++dpg[i];
      if(temp[cb] != given[i]) ++dpb[i];
      if(given[i-k] != temp[2]) --dpr[i];
      if(given[i-k] != temp[0]) --dpg[i];
      if(given[i-k] != temp[1]) --dpb[i];
      mi = min(mi, dpr[i]);
      mi = min(mi, dpg[i]);
      mi = min(mi, dpb[i]);
    }
    cout << mi << endl;
  }
}