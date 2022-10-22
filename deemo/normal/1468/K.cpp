#include <bits/stdc++.h>
#define MAXN 1000100
#define pii pair<int, int>
#define vi vector<int>
#define pb push_back
#define inf 1e18
#define fi first
#define se second
#define mt make_tuple
typedef long long ll;

using namespace std;

int n, T;
map<char, int> X, Y;
string s;

int go(int a, int b){
	//obstacle at x, y
	int x = 0, y = 0;
	for(char c : s){
		if(x + X[c] == a and y + Y[c] == b) continue;
		x += X[c];
    	y += Y[c];
	}
	return (x == 0) and (y == 0);
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    X['R'] = 1;
    X['L'] = -1;
    Y['U'] = 1;
    Y['D'] = -1;
    while(T--){
    	cin >> s;
    	n = s.size();
    	int x = 0, y = 0;
    	for(char c : s){
    		x += X[c];
    		y += Y[c];
    		if(go(x, y)){
    			break;
    		}
    	}
    	if(go(x, y)) cout << x << " " << y << endl;
    	else cout << "0 0" << endl;
    }
}