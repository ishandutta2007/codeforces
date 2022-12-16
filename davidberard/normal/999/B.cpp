#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int N;
    cin >> N;
    string s;
    cin >> s;
    for(int i=1;i<=N;++i) {
        if(N%i == 0) {
            reverse(s.begin(),s.begin()+i);
        }
    }
    cout << s << endl;

    return 0;
}