#include <iostream>

using namespace std;
long long stations[100002];
long long visited[100002];
long long count = 0;
void search(long long a){
    if(visited[a] != 0){
        return;
    }
    visited[a] = 1;
    count++;
    search(stations[a]);
}
int main() {
    long long ans = 0;
    long long n;
    long long maxc = 0;
    long long maxc2 = 0;
    cin >> n;
    for(long long i = 1; i < n+1; i++){
        long long p;
        cin >> p;
        stations[i] = p;
    }
    for(long long i = 1; i < n+1; i++){
        if(visited[i]==0){
            search(i);
        }
        ans += count*count;
        if(count >= maxc2){
            maxc2 = min(maxc, count);
            maxc = max(maxc, count);
        }

        count = 0;
    }
    if(n == 1){
    cout << ans;
    }
    else{
        cout << ans + 2 * maxc * maxc2;
    }
}