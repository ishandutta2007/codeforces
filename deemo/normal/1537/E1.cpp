#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 10;

string s;
int n, k, z[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> k;
	cin >> s;
    s += s;
    n <<= 1;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++)
		if (r <= i){
			l = r = i;
			while (r < n && s[r] == s[r-l]) r++;
			z[i] = r-i;
		}
		else{
			if (z[i-l] < (r - i))
				z[i] = z[i-l];
			else{
				l = i;
				while (r < n && s[r] == s[r-l]) r++;
				z[i] = r-i;
			}
		}

    n >>= 1;
    int t = 1;
    while (t < n) {
        if (z[t] < t && t + z[t] < (int)s.size() && s[t+z[t]] > s[z[t]]) break;
        t++;
    }

    if (t > k)
        t = k;

    for (int i = 0; i < k; i++)
        cout << s[i%t];
    cout << "\n";

	return 0;
}