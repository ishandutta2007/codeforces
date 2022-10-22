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

Int get_area(Int a, Int b, Int c){
    Int ans;
    cout << 1 << " " << a << " " << b << " " << c << endl;
    cin >> ans;
    return ans;
}

Int get_sign(Int a, Int b ,Int c){
    Int ans;
    cout << 2 << " " << a << " " << b << " " << c << endl;
    cin >> ans;
    return ans == 1;
}

Int n;
vector<P> up, down;
vector<Int> tl, tr, bl, br;

int main(){
    cin >> n;
    Int a = 1, b = 2;
    for(Int c = 3;c <= n;c++){
        if(get_sign(a,b,c))
            up.push_back(P(get_area(a,b,c),c));
        else
            down.push_back(P(get_area(a,b,c),c));       
    }
    up.push_back(P(0,a));
    down.push_back(P(0,b));
    sort(up.begin(), up.end());
    sort(down.begin(), down.end());
    Int top = up.back().second;
    Int bottom = down.back().second;
    
    for(auto p: up){
        Int x = p.second;
        if(x == top)continue;
        if(get_sign(bottom, top, x))tl.push_back(x);
        else tr.push_back(x);
    }

    for(auto p: down){
        Int x = p.second;
        if(x == bottom)continue;
        if(get_sign(bottom, top, x))bl.push_back(x);
        else br.push_back(x);
    }
    vector<int> ans;
    cout << 0;
    ans.push_back(bottom);
    for(auto it = br.rbegin();it != br.rend();it++)ans.push_back(*it);

    for(auto it = tr.begin();it != tr.end();it++)ans.push_back(*it);

ans.push_back(top);
    for(auto it = tl.rbegin();it != tl.rend();it++)ans.push_back(*it);
    for(auto it = bl.begin();it != bl.end();it++)ans.push_back(*it);
    int start = 0;
    while(ans[start] != 1)start++;
    for(int i = 0;i < n;i++){
        cout << " " << ans[(start+i)%n];
    }
    cout << endl;
    return 0;
}