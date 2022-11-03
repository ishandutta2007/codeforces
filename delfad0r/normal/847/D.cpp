#include <bits/stdc++.h>

using namespace std;

int N, T;
int t[200002];
int main() {
    cin >> N >> T;
    for(int n = 1; n <= N; ++n) {
        cin >> t[n];
    }
    
    priority_queue<int> pq;
    int ans = 0;
    for(int i=1; i<=N; i++){
        int ta = T - i - 1;
        //~ pq.push(t[i]-i);//?
        while(!pq.empty()){
            int v = pq.top();
            if(v > ta){
                pq.pop();
            }else{
                break;
            }
        }
        int nans = pq.size();
        if(max(t[i],i) < T){
            nans++;
            ans = max(ans, nans);
        }
        
        pq.push(t[i]-i);
    }
    cout << ans << '\n';
    return 0;
}