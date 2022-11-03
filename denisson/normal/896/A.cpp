#include <bits/stdc++.h>
                   
using namespace std;
           
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

string s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string stmp[3] = {"What are you doing while sending \"", "\"? Are you busy? Will you send \"", "\"?"};

ll len[111];

bool isBigger(ll n, ll k){
	if (n >= 111) return 1;
	if (len[n] == -1) return 1;
	return len[n] >= k;
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tt;
    cin >> tt;
    len[0] = s0.size();
    for (int i = 1; i < 111; i++){
    	if (len[i - 1] == -1 || len[i - 1] > 1e18) len[i] = -1; else 
    	len[i] = (ll)2 * len[i - 1] + (ll)stmp[0].size() + (ll)stmp[1].size() + (ll)stmp[2].size(); 
    }

    string ss = stmp[0] + s0;
    ss += stmp[1];
    ss += s0;
    ss += stmp[2];
    //cout << len[1] << ' ' << ss << endl;
    while(tt--){
    	ll n, k;
    	cin >> n >> k;
    	if (!isBigger(n, k)){
    		cout << ".";
    		continue;
    	}
    	int v = n;
    	char c;
    	while(1){
    		if (v == 0){
    			c = s0[k - 1];
    			break;
    		}

    		if (stmp[0].size() >= k){
    			c = stmp[0][k - 1];
    			break; 
    		} else k -= stmp[0].size();

    		if (isBigger(v - 1, k)){
    			v--;
    			continue;
    		} else k -= len[v - 1];

    		if (stmp[1].size() >= k){
    			c = stmp[1][k - 1];
    			break; 
    		} else k -= stmp[1].size();

    		if (isBigger(v - 1, k)){
    			v--;
    			continue;
    		} else k -= len[v - 1];

    		c = stmp[2][k - 1];
    		break;
    	}
    	cout << c;
    }
}