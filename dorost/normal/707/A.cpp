//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  short n,m;
  cin >> n >> m;
  char c;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      cin >> c;
      if(c == 'W' || c == 'B' || c == 'G'){}
      else{
        cout << "#Color";
        return 0;
      }
    }
  }
  cout << "#Black&White";
}