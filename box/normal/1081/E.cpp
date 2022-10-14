    #include <bits/stdc++.h>
    #define iter(i, a, b) for(int i=(a); i<(b); i++)
    #define rep(i, a) iter(i, 0, a)
    #define log(a) cerr<<"\033[32m[DEBUG] "<<#a<<'='<<(a)<<" @ line "<<__LINE__<<"\033[0m"<<endl
    #define all(a) a.begin(), a.end()
    #define fi first
    #define se second
    #define pb push_back
    #define mp make_pair
    using namespace std;
    using ll=long long;
    using pii=pair<int, int>;
    #define int ll
     
    int y[100005];
     
    signed main() {
    	ios_base::sync_with_stdio(false); cin.tie(0);
    	int N; cin >> N;
    	for(int i=2; i<=N; i+=2) {
    	    int xi; cin >> xi;
    	    y[i] = 0xFFFFFFFFFFull;
    	    for(int a=1; a*a <= xi; a++) {
    	        int vv = xi/a-a;
    	        if(xi%a || vv%2 || vv/2 <= y[i-2] || a+vv/2 >= y[i]) continue;
    	        y[i-1] = vv/2; y[i] = a+y[i-1];
    	    }
    	    if(y[i] == 0xFFFFFFFFFFull) {
    	        N = -1;
    	        break;
    	    }
    	}
    	if(N == -1) {
    	    cout << "No" << endl;
    	    return 0;
    	}
    	cout << "Yes" << endl;
    	cout << y[1]*y[1];
    	for(int i=2; i<=N; i++) cout << ' ' << y[i]*y[i] - y[i-1]*y[i-1];
    	cout << endl;
    }