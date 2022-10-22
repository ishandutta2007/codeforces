#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;

const ll MAXN = 2e5 + 10;

ll n;
ll vec[MAXN], sum;
ll q[MAXN], h, t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (ll i = 0; i < n; i++)
		cin >> vec[i], sum += vec[i];
	
	sum /= n;
	ll ans = 0, c = 0;
	for (ll i = 0; i < n; i++){
		ans += c;
		if (vec[i] == sum)	continue;

		if (vec[i] < sum){
			if (c){
				ll mini = min(c, sum - vec[i]);
				c -= mini;
				vec[i] += mini;
			}
			if (vec[i] < sum)	q[t++] = i;
		}
		else{
			ll z = vec[i] - sum;
			while (h < t && z){
				ll mini = min(z, sum - vec[q[h]]);
				z -= mini;
				vec[q[h]] += mini;
				ans += mini * (i - q[h]);
				if (vec[q[h]] == sum)	h++;
			}

			if (z)
				c += z;
		}
	}
	cout << ans << endl;
	return	0;
}