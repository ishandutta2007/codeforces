// 23.46
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 305000;

queue<int> app[MAXN];
vector<int> notification;
int first_unread;
int last;
int res;
int N, Q;

int main() {
    // ofstream cout("output.txt");
    ios::sync_with_stdio(false);
    cin >> N >> Q;
    for (int i = 0; i < Q; i++) {
        int t,x;
        cin >> t >> x;
        if (t == 1) {
            app[x].push(notification.size());
            notification.push_back(x);
            res++;
        } else if (t == 2) {
            res -= app[x].size();
            app[x] = queue<int>();
        } else {
            while (first_unread < x) {
                if (!app[notification[first_unread]].empty()) { 
                    if (app[notification[first_unread]].front() == first_unread) {
                        res--;
                        app[notification[first_unread]].pop();
                    }
                }
                first_unread++;
            }
        }
        cout << res << "\n";
    }
}