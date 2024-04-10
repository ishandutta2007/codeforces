#include <algorithm>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct boxA {
    int a, b, id;
    const bool operator<(const boxA other) const {
        return a < other.a;
    }
};

vector<boxA> boxes;

int DP[5005], parent[5005];

int main() {
    int n, w, h; cin >> n >> w >> h;
    int N = 0;
    for(int i=0; i<n; i++) {
        int W, H; cin >> W >> H;
        if(w < W && h < H) boxes.push_back({W, H, i+1});
    }
    sort(boxes.begin(), boxes.end());
    N = boxes.size();
    if(N == 0) {
        cout << 0 << endl;
        return 0;
    }
    memset(parent, 255, sizeof parent);
    DP[0] = 1;
    int longest = 0;
    for(int i=1; i<N; i++) {
        DP[i] = 1;
        for(int j=0; j<i; j++)
            if(boxes[j].a < boxes[i].a && boxes[j].b < boxes[i].b && DP[j] >= DP[i]) {
                DP[i] = DP[j]+1;
                parent[i] = j;
            }
        if(DP[i] > DP[longest]) longest = i;
    }
    cout << DP[longest] << endl;
    stack<int> path;
    while(parent[longest] != -1) {
        path.push(longest);
        longest = parent[longest];
    }
    cout << boxes[longest].id;
    while(!path.empty()) {
        cout << ' ' << boxes[path.top()].id;
        path.pop();
    }
    cout << endl;
}