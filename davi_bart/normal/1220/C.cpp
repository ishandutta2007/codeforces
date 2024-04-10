#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll p[1001][1001];
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    string s;
    cin >> s;
    int mi =100000;
    for(char ch : s) {
      if (ch > mi) {
        cout << "Ann\n";
      } else {
        cout << "Mike\n";
        mi = ch;
      }
    }
  }