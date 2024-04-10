#include <bits/stdc++.h>
using namespace std;
#define MAXN 250005
#define MAXM 10000005

int n, m, q, curid = 0;
vector<array<int, 2>> blocks[MAXN];
array<long long, 2> arr[MAXM]; // 0: height, 1 : cost
int leftend[MAXM], rightend[MAXM];
long long dp[MAXM];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        int k; cin >> k; blocks[i].resize(k);
        for(int j = 0; j<k; j++) cin >> blocks[i][j][0];
        for(int j = 0; j<k; j++) cin >> blocks[i][j][1];
    } cin >> q;
    while(q--){
        int id; long long mul; cin >> id >> mul; --id;
        for(int i = 0; i<blocks[id].size(); i++) arr[curid++] = {blocks[id][i][0], mul*blocks[id][i][1]};
    }
    // for(int i = 0; i<m; i++) cout << arr[i][1] << " ";
    // cout << endl;
    deque<array<int, 2>> dqleft; // 0: value, 1: id;
    for(int i = 0; i<m; i++){
        int curmin = i;
        while(!dqleft.empty() && i-dqleft.front()[1] < arr[i][0]) curmin = dqleft.front()[0], dqleft.pop_front();
        leftend[i] = curmin; dqleft.push_front({curmin, i});
    }
    deque<array<int, 2>> dqright;
    for(int i = m-1; i>=0; i--){
        int curmax = i;
        while(!dqright.empty() && dqright.front()[1]-i < arr[i][0]) curmax = dqright.front()[0], dqright.pop_front();
        rightend[i] = curmax; dqright.push_front({curmax, i});
    }
    // for(int i = 0; i<m; i++) cout << leftend[i]+1 << " ";
    // cout << endl;
    deque<array<long long, 2>> dq; //0: value, 1: id;
    for(int i = 0; i<m; i++){
        //transition 1:
        dp[i] = (leftend[i] == 0)?arr[i][1]:arr[i][1]+dp[leftend[i]-1];
        //transiton 2:
        while(!dq.empty() && rightend[dq.front()[1]] < i) dq.pop_front();
        if(!dq.empty()) dp[i] = min(dp[i], dq.front()[0]);
        if(dq.empty() || ((i == 0)?0:dp[i-1])+arr[i][1] < dq.front()[0]) dq.push_front({((i == 0)?0:dp[i-1])+arr[i][1], i});
    }
    // for(int i = 0; i<m; i++) cout << dp[i] << " ";
    // cout << endl;
    cout << dp[m-1] << endl;
}