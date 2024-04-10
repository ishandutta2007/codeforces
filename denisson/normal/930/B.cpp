#include <bits/stdc++.h>
                     
using namespace std;
             
typedef long long ll;
#define mp make_pair    
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

string s;
vector<int> t[26];
int was[26];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    int n = s.size();
    s += s;
    for (int i = 0; i < n; i++){
    	t[s[i] - 'a'].pb(i);
    }

    int ans = 0;

    for (int c = 0; c < 26; c++){
    	int ma = 0;
    	/*for (int v : t[c]){
    		for (int i = 0; i < n; i++) cout << s[v + i];
    		cout << endl;
    	}
    	cout << endl;*/
    	for (int i = 0; i < n; i++){
    		for (int j = 0; j < 26; j++) was[j] = 0;
    		for (int v : t[c]){
    			was[s[i + v] - 'a']++;
    		}

    		int gg = 0;
    		for (int j = 0; j < 26; j++) if (was[j] == 1) gg++;
    		ma = max(ma, gg);
    	}
    	ans += ma;
    }
    cout.precision(10);
    cout << fixed << ans / (db)n;
}