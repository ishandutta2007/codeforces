#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
typedef long long LL;
const int SIZE = 1 << 20;
struct Building {
    int id;      // 
    LL v;        //  id 
    LL ans;      //  1  id 
};
int h[SIZE];
int b[SIZE];
int n;
void solve() {
    stack<Building> stk;
    for(int i = 1; i <= n; i++) {
        LL v = stk.empty() ? 0 : stk.top().ans; //  i 
        while(!stk.empty() && h[i] < h[stk.top().id]) {
            /*  stack 
             * stack 
             */
            v = max(v, stk.top().v - b[stk.top().id]);
            stk.pop();
        }
        v += b[i];
        stk.push({i, v, stk.empty() ? v : max(v, stk.top().ans)});
    }
    cout << stk.top().ans << '\n';
}
void input() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> h[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
}
int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    input();
    solve();
    return 0;
}