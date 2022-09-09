#include<bits/stdc++.h>
using namespace std;
int reflection[10] = {0, 1, 5, -1, -1 ,2, -1, -1, 8, -1};
int h, m;
void advance(int &x, int &y) {
    y++;
    if(y == m) {
        y = 0;
        x++;
        if(x == h) x = 0;
    }
}
bool valid(int x, int y) {
    string s_x = to_string(x);
    string s_y = to_string(y);
    if(s_x.size() == 1) s_x = "0" + s_x;
    if(s_y.size() == 1) s_y = "0" + s_y;
    reverse(s_x.begin(), s_x.end());
    reverse(s_y.begin(), s_y.end());
    for(char &c: s_x) {
        if(reflection[c - '0'] == -1) return 0;
        c = reflection[c - '0'] + '0';
    }
    for(char &c: s_y) {
        if(reflection[c - '0'] == -1) return 0;
        c = reflection[c - '0'] + '0';
    }
    return stoi(s_y) < h && stoi(s_x) < m;
}
void solve() {
    cin >> h >> m;
    int x, y;
    char c;
    cin >> x >> c >> y;
    while(1) {
        if(valid(x, y))  {
            cout << setfill('0') << setw(2) << x << ":" << setfill('0') << setw(2)  << y << '\n';
            return;
        }
        advance(x, y);
        
    }
}
int main() {
    int T;
    cin >> T;
    while(T--) solve();
    return 0;
}