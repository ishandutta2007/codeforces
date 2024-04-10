#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <set>

using namespace std;

const int N = 5e4 + 5;
string s;
int tot, a[105], cnt, sum;

int main() {
    int t;
    cin >> t;
    while(t--) {
        tot = cnt = sum = 0;
        cin >> s;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '1') {
                while(s[i] == '1' && i < s.size()) {
                    ++cnt;
                    ++i;
                }
                a[++tot] = cnt;
                cnt = 0;
            }
        }
        sort(a + 1, a + tot + 1, greater<int>());//
        for(int i = 1; i <= tot; i += 2) sum += a[i];
        printf("%d\n", sum);
    }   
    return 0;
}