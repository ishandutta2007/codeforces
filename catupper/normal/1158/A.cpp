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
using namespace std;
#define MOD 1000000007
#define INF (1<<29)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

void ok(){
    cout << "Yes" << endl;
    exit(0);
}

void ng(){
    cout <<  "-1" << endl;
    exit(0);
}

vector<Int> bs, gs;
int main(){
    Int n, m, b, g;
    cin >> n >> m;
    Int maxb = 0;

    Int res = 0;
    for(int i = 0;i < n;i++){
        cin >> b;
        res += b * m;
        bs.push_back(b);
    }
    sort(bs.begin(), bs.end());
    for(int i = 0;i < m;i++){
        cin >> g;
        if(g < bs.back())ng();;
        gs.push_back(g);
    }
    sort(gs.begin(), gs.end());
    
    for(auto g:gs)res += g-bs.back();
    if(gs[0] != bs.back()){
        res += bs.back() - bs[bs.size() - 2];
    }
    cout << res << endl;
    return 0;
}