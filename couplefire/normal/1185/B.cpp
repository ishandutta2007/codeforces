#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  for(int i = 0; i<n; i++){
    string a, b;
    cin >> a >> b;
    int it = 0;
    bool work = b.size() >= a.size();
    for(int k = 0; k<b.length(); k++){
      if(b[k] == a[it]){
        it++;
      }
      else{
        if((k == 0) || (k > 0 && b[k] != b[k-1])){
          work = false;
          break;
        }
      }
    }
    if(work && it >= a.size()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }
}

/*

ababababababababababababab
abababababababababababab

*/