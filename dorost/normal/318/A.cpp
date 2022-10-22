//in the name of GOD//

#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie();
#define sz(s) s.size()

int main(){
  ll n,m;
  cin >> n >> m;
  if(m > (n + 1) / 2){
    cout << m * 2 - n - (n % 2);
  }else{
    cout << m * 2 - 1;
  }
}