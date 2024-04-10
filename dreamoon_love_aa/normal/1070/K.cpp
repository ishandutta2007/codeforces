#include<bits/stdc++.h>
using namespace std;
#define N 100010
int n, k, sum = 0;
int a[N], s[N];
bool solve () {
    if(sum % k) {
        return false;
    }
    int id = 0;
    for(int i = 0, j; i < n; i = j) {
        int now = 0;
        for(j = i; j < n && now < sum / k; j++) {
            now += a[j];
        }
        if(now != sum / k) {
            return false;
        }
        s[id++] = j - i;
    }
    return true;
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
	}
	if(!solve()) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        for(int i = 0; i < k; i++) {
            cout << s[i] << " ";
        }
        cout << endl;
    }
	return 0;
}