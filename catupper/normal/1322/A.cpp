#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int n;
string str;
int cnt;

int main(){
    cin >> n;
    cin >> str;
    int level = 0;
    for(int i = 0;i < n;i++){
        if(str[i] == '('){
            if(level < 0)cnt++;
            level++;
        }
        else {
            level--;
            if(level < 0)cnt++;
        }
    }
    if(level != 0)cnt = -1;
    cout << cnt << endl;
    return 0;
}