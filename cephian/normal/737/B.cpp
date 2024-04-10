#include <iostream>
#include <vector>

using namespace std;

int n,a,b,k;
string s;
const int N = 200005;
int nl[N],nr[N];

vector<int> guess;

int main() {
    ios::sync_with_stdio(0);
    cin >> n >> a >> b >> k;
    cin >> s;
    n = s.size();

    int last = -1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1')
            last = i;
        nl[i] = last;
    }

    int placed = 0;
    for(int i = n-1; i>= 0; --i) {
        if(s[i] == '1') continue;
        if(i-nl[i] < b) continue;
        int stop = i-b;
        ++placed;
        while(i != stop) {
            s[i] = '2';
            --i;
        }
        ++i;
        if(placed == a) break;
    }
    last = n;
    for(int i = n; i >= 0; --i) {
        if(s[i] == '1')
            last = i;
        nr[i] = last;
    }
    int last_reset = -1;
    for(int i = 0; i < n; ++i) {
        if(s[i] == '1') {
            last_reset = i;
            continue;
        }
        if(i-last_reset != b) continue;
        last_reset = i;
        guess.push_back(i);
        if(s[i] == '2') break;
    }
    cout << guess.size() << "\n";;
    for(int i = 0; i < guess.size(); ++i) {
        if(i) cout << " ";
        cout << guess[i]+1;
    }
    cout << "\n";

    return 0;
}