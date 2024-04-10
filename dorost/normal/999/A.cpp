#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
    int n, k, x;
    cin >> n >> k;
    deque <int> dq;
    dq.clear();
    for (int i = 0; i < n; i++) {
        cin >> x;
        dq.push_back(x);
    }
    for(int i = 0; i < n; i++){
        if(dq[0] > k){
            break;
        }
        if(dq.size())
            dq.pop_front();
    }
     for(int i = 0; i < n; i++){
        if(dq.back() > k){
            break;
        }
        if (dq.size())
            dq.pop_back();
    }
    cout << n - dq.size();
}