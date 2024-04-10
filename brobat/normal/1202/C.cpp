#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve(vector<char> &v) {
    int mn_x{0}, mn_y{0}, mx_x{0}, mx_y{0}, curr_x{0}, curr_y{0};
    for(auto i : v) {
        if(i == 'W') {
            curr_x--;
        } else if(i == 'S') {
            curr_x++;
        } else if(i == 'D') {
            curr_y++;
        } else if(i == 'A') {
            curr_y--;
        }
        mn_x = min(mn_x, curr_x);
        mn_y = min(mn_y, curr_y);
        mx_x = max(mx_x, curr_x);
        mx_y = max(mx_y, curr_y);
    }
    int ans = (mx_x - mn_x + 1) * (mx_y - mn_y + 1);
    // for(auto i : v) cerr << i;
    // cerr << " " << ans << '\n';
    return ans;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        int mn_x{0}, mn_y{0}, mx_x{0}, mx_y{0}, curr_x{0}, curr_y{0};
        int mn_xi{0}, mn_yi{0}, mx_xi{0}, mx_yi{0};
        int j = -1;
        for(auto i : s) {
            j++;
            if(i == 'W') {
                curr_x--;
            } else if(i == 'S') {
                curr_x++;
            } else if(i == 'D') {
                curr_y++;
            } else if(i == 'A') {
                curr_y--;
            }
            if(curr_x < mn_x) {
                mn_x = curr_x;
                mn_xi = j;
            }
            if(curr_y < mn_y) {
                mn_y = curr_y;
                mn_yi = j;
            }
            if(curr_x > mx_x) {
                mx_x = curr_x;
                mx_xi = j;
            }
            if(curr_y > mx_y) {
                mx_y = curr_y;
                mx_yi = j;
            }
        }
        vector<char> v;
        for(auto i : s) v.push_back(i);
        int ans = solve(v);

        v.insert(v.begin() + mn_xi, 'S');
        ans = min(ans, solve(v));
        v.erase(v.begin() + mn_xi);

        v.insert(v.begin() + mx_xi, 'W');
        ans = min(ans, solve(v));
        v.erase(v.begin() + mx_xi);

        v.insert(v.begin() + mn_yi, 'D');
        ans = min(ans, solve(v));
        v.erase(v.begin() + mn_yi);

        v.insert(v.begin() + mx_yi, 'A');
        ans = min(ans, solve(v));
        v.erase(v.begin() + mx_yi);

        cout << ans << '\n';
    }   
    
    return 0;
}