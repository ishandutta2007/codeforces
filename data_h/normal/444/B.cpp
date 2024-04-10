#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

const int N = 111111;

int n, d, x;
int a[N], b[N], c[N];

int getNextX() {
    x = (1LL * x * 37 + 10007) % 1000000007;
    return x;
}

int main() {
	scanf("%d %d %d", &n, &d, &x);
	for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
    if (d < sqrt(n)) {
    	vector<int> ones;
		for(int i = 0; i < n; i++) {
			if (b[i] == 1)
				ones.push_back(i);
		}
		for(int i = 0; i < n; i++)
			for(int j = 0; j < (int)ones.size() && i + ones[j] < n; j++) {
				c[i + ones[j]] = max(c[i + ones[j]], a[i]);
			}
    } else {
    	static int pos[N]; 
    	for(int i = 0; i < n; i++) {
    		pos[a[i]] = i;
    	}
    	set<int> s;
    	for(int i = 0; i < n; i++) {
    		s.insert(a[i]);
    		set<int> :: iterator it = s.end();
			for(--it; ; --it) {
				if (b[i - pos[*it]]) {
					c[i] = *it;
					break;
				}
				if (it == s.begin())
					break;
			}
    	}
    }
    for(int i = 0; i < n; i++) {
    	printf("%d\n", c[i]);
    }
	return 0;
}