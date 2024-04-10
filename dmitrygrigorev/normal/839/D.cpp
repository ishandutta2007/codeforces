#include <bits/stdc++.h>
#define int long long
#define D long double
using namespace std;
int INF = 1000001;
int MOD = 1000000007;
signed main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i=0; i < n; i++) cin >> v[i];
    vector<int> steps(INF), numbers(INF), answers(INF), del(INF);
    steps[0] = 1;
    for (int i=1; i < INF; i++) steps[i] = (steps[i-1] * 2) % MOD;
    fill(numbers.begin(), numbers.end(), 0);
    fill(answers.begin(), answers.end(), 0);
    fill(del.begin(), del.end(), 0);
    for (int i=0; i < n; i++){
        numbers[v[i]]++;
    }
    for (int i=INF-1; i > 0; i--){
        for (int j=i; j < INF; j+=i){
            del[i] += numbers[j];
        }
    }
    int ans = 0;
    for (int i=INF-1; i > 1; i--){
        if (!del[i]) continue;
        int var = steps[del[i] - 1] * del[i];
        var %= MOD;
        for (int j=2*i; j < INF; j+=i) {
            var -= answers[j];
            var %= MOD;
        }
        var %= MOD;
        if (var < 0) var += MOD;
        answers[i] = var;
        ans += (var * i);
        ans %= MOD;
    }
    cout << ans % MOD << endl;
    return 0;
}