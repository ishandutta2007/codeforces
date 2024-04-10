#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000100;

int ans1[maxn];
int ans2[maxn];
bool a[maxn];

int mind[maxn];

int main() {

    //freopen("input", "r", stdin);
    //freopen("output", "w", stdout);

    int x2;
    cin >> x2;	

    const int inf = 1e9;
    for (int i = 0; i != maxn; ++i)
        mind[i] = i;
	
    auto pdivs = [&](int val) {
        vector<int> res;
		
        while (val != 1) {
            res.push_back(mind[val]);
            int d = mind[val];
            while (val % d == 0)
                val /= d;		
        }
        return res;
    };

    int i = 2;
    while (i <= x2) {
        int j = i + i;
        while (j <= x2) {
            a[j] = 1;
            mind[j] = min(mind[j], i);
            j += i;
        }
        i++;
    }
    for (int i = 0; i <= x2; ++i) ans1[i] = x2 + 1;
    for (int i = 0; i <= x2; ++i) ans2[i] = x2 + 1;
    for (int x = 2; x <= x2; ++x) {
        for (int p: pdivs(x)) {
            if (p != x)
                ans1[x] = min(ans1[x], x - p + 1);
        }
    }
    
    for (int x = x2; x <= x2; ++x) {
        for (int p: pdivs(x)) {
            if (p != x) 
                for (int i = x - p + 1; i <= x; ++i) {
                    ans2[x] = min(ans2[x], ans1[i]);
                }
        }
    }
    cout << ans2[x2] << endl;
	
    return 0;
}