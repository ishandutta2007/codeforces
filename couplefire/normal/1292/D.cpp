#include <bits/stdc++.h>
using namespace std;
 
vector<pair<int, int>> prime_division(int n){
    vector<pair<int, int>> ret;
    for(int i=2; i*i<=n; i++){
        int cnt = 0;
        while(n % i == 0){
            n /= i;
            cnt++;
        }
        if(cnt) ret.emplace_back(i, cnt);
    }
    if(n > 1) ret.emplace_back(n, 1);
    return ret;
}
 
int main(){
    const int M = 5000;
    static int num[M+1][M+1], mx[M+1], sum[M+1];
    for(int i=1; i<=M; i++){
        auto pd = prime_division(i);
        for(auto& p : pd) num[i][p.first] += p.second;
        for(int j=1; j<=M; j++){
            num[i][j] += num[i-1][j];
            sum[i] += num[i][j];
            if(num[i][j]) mx[i] = j;
        }
    }
 
    int64_t ans = 0;
    static int cnt[M+1];
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int k;
        scanf("%d", &k);
        if(k == 0) k = 1;
        cnt[k]++;
        ans += sum[k];
    }
 
    static int current[M+1];
    bitset<M+1> dead;
    dead[1] = 1;
    while(true){
        int nxt = -1;
        int dir[M+1] = {0};
        for(int k=1; k<=M; k++) if(!dead[k]){
            dir[mx[k]] += cnt[k];
            if(dir[mx[k]]*2 > N) nxt = mx[k];
        }
        if(nxt == -1) break;
        ans += N - dir[nxt]*2;
        current[nxt]++;
        for(int k=1; k<=M; k++) if(!dead[k]){
            if(mx[k] != nxt){
                dead[k] = 1;
            }else{
                while(mx[k] > 1 && num[k][mx[k]] == current[mx[k]]) mx[k]--;
                if(mx[k] == 1) dead[k] = 1;
            }
        }
    }
    cout << ans << endl;
}