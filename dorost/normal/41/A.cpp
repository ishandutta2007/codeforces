//*in the name of GOD*\\

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
typedef long double ld;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main(){
  string s,t;
  cin >> s >> t;
  for(int i = 0; i < t.size() / 2;i++){
    swap(t[i] , t[t.size() - i - 1]);
  }
  if(s == t){
    cout << "YES";
  }else{
    cout << "NO";
  }
}