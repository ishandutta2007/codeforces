#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<complex>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
#define PI 3.1415926535897932384626433832795028
typedef long long Int;
typedef pair<Int, Int> P;
typedef long double Real;
typedef complex<Real> CP;

Int a[33];
Int d[66];

bool dp[33][66][2500];
int before[33][66][2500];

bool edge[110][110];

void make_graph(vector<int> vs){
//    for(int i = 0;i < vs.size();i++)cout << vs[i] << " " ;cout << endl;
    int n = vs.size();
    if(n == 1)return;
    sort(vs.begin(), vs.end());
    vector<int> cnt(33, 0);
    for(int i = 0;i < n-1;i++){
        if(i < vs.back())cnt[vs[i]]++;
        else vs[i]--;
    }
//    for(int i = 0;i < vs.size();i++)cout << vs[i] << " " ;cout << endl;
    vs.pop_back();
    make_graph(vs);
    for(int i = 0;i < n-1;i++){
        if(cnt[d[i]]){
            edge[n-1][i] = true;
            cnt[d[i]]--;
            d[n-1]++;
        }
        else{
            d[i]++;
            edge[i][n-1] = true;
        }
    }
}

int main(){
    int m;
    cin >> m;
    for(int i = 0;i < m;i++)cin >> a[i];
    sort(a, a + m);
    dp[0][1][a[0]] = true;
    for(Int i = 0;i < m;i++){
        for(int j = 0;j < 66;j++){
            for(int k = 2499;k >= 0;k--){
                if(k < j * (j-1) / 2)break;
                if(!dp[i][j][k])continue;
                if(k + a[i] < 2500){
                    dp[i][j+1][k+a[i]] = true;
                    before[i][j+1][k+a[i]] = i;
                }
                if(i+1 < m && k + a[i+1] < 2500){
                    dp[i+1][j+1][k+a[i+1]] |= dp[i][j][k];
                    before[i+1][j+1][k+a[i+1]] = i;
                }
            }
        }
    }
    Int v = -1;
    for(Int j = 1;j < 66;j++){
        if(dp[m-1][j][j*(j-1)/2]){
            v = j;
            break;
        }
    }
    if(v == -1){
        cout << "=(" << endl;
        return 0;
    }
    vector<int> vs;
    int now_i = m-1;
    int now_k = v*(v-1)/2;
    for(int j = v;j > 0;j--){
        vs.push_back(a[now_i]);
        int before_i = before[now_i][j][now_k];
        now_k -= a[now_i];
        now_i = before_i;
    }
    int n = vs.size();
    make_graph(vs);
    cout << n << endl;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(edge[i][j])putchar('1');
            else putchar('0');
        }
        puts("");
    }    
    return 0;
}