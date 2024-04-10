#include<bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define MP make_pair
#define PB emplace_back
using namespace std;
void solve(){
    string x;
    cin >> x;
    int answer = 0;
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 4; j++) {
            answer += j;
            if(string(j, i + '0') == x) {
                cout << answer << endl;
                return;
            }
        }
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--){
        solve();
    }
    return 0;
}