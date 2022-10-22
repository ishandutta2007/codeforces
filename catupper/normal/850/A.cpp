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

vector<int> ans;
int n;
Int val[1100][10];

bool accute(Int o, Int a, Int b){
    Int ip = 0;
    for(int i = 0;i < 5;i++){
        ip += (val[a][i] - val[o][i]) * (val[b][i] - val[o][i]);
    }
    return ip > 0;
}

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < 5;j++){
            cin >> val[i][j];
        }
    }
    if(n > 100){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0;i < n;i++){
        bool ok = true;
        for(int j = 0;j < n;j++){
            for(int k = j+1;k < n;k++){
                if(j == i || k == i)continue;
                if(accute(i, j, k))ok = false;
            }
        }
        if(ok)ans.push_back(i+1);
    }
    cout << ans.size() << endl;;
    for(int i = 0;i < ans.size();i++)cout << ans[i] << endl;
    
    return 0;
}