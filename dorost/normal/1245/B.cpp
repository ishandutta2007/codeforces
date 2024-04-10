//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  while(t--){
    int n,a,b,c;
    string s;
    cin >> n >> a >> b >> c >> s;
    int ans = 0;
    char t[n];
    for(int i = 0; i < n; i++){
      t[i] = '#';
    }
    for(int i = 0; i < n; i++){
      if(s[i] == 'R' && b){
        t[i] = 'P';
        b--;
        ans++;
      }else if(s[i] == 'P' && c){
        t[i] = 'S';
        c--;
        ans++;
      }else if(s[i] == 'S' && a){
        t[i] = 'R';
        a--;
        ans++;
      }
    }
    for(int i = 0; i < n; i++){
      if(t[i] == '#'){
        if(a){
          t[i] = 'R';
          a--;
        }else if(b){
          t[i] = 'P';
          b--;
        }else if(c){
          t[i] = 'S';
          c--;
        }
      }
    }
    if(ans >= (long double)n / 2.0){
      cout << "YES" << endl;
      for(int i = 0; i < n; i++){
        cout << t[i];
      }
      cout << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}