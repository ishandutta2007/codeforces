#include <bits/stdc++.h>
      
using namespace std;
      
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()

int n;
set<string> se;

int main(){ 
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++){
    	string s;
    	cin >> s;
    	if (se.find(s) == se.end()) cout << "NO\n";
    	else cout << "YES\n";
    	se.insert(s);
    }
}