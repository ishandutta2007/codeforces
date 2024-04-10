#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

string s;
int ans = 0;

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    set<char> se;
    se.insert('a');
    se.insert('e');
    se.insert('i');
    se.insert('o');
    se.insert('u');
    for (char c : s){
    	if (c >= '0' && c <= '9'){
    		int now = c - '0';
    		if (now % 2 == 1){
    			ans++;
    		}
    	} else {	
    		if (se.find(c) != se.end()) ans++;
    	}
    }
    cout << ans;
}