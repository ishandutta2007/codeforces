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
int pref[5555];

int get(int l, int r){
	return pref[r + 1] - pref[l];
}

int main(){ 
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //freopen("heavy.in", "r", stdin);
    //freopen("heavy.out", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    for (int i = 0; i < s.size(); i++){
    	pref[i + 1] = pref[i] + (s[i] == 'b');
    }
    int ans = 0;

    for (int i = 0; i <= s.size(); i++){
    	for (int j = i; j <= s.size(); j++){
    		int now = s.size();

    		if (i){
    			now -= get(0, i - 1);
    		}

    		if (j){
    			now -= (j - i) - get(i, j - 1);
    		}

    		if (j < s.size()) now -= get(j, (int)s.size() - 1);

    		//cout << i << ' ' << j << ' ' << now << endl;

    		ans = max(ans, now);
    	}
    }

    cout << ans;
}