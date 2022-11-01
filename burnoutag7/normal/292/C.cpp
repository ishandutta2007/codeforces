/******************
* Writer:  rng_58 *
******************/
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

vector <string> ans;

bool check(string s, int L, int R){
    if(s[L] == '0'){
        if(R == L + 1) return true;
        return false;
    }
    
    int x = 0;
    int i;
    for(i=L;i<R;i++) x = x * 10 + (s[i] - '0');
    return (x >= 0 && x < 256);
}

void func(string s){
    int N=s.length(),i,j,k;
    
    for(i=1;i<=3;i++) for(j=i+1;j<=i+3;j++) for(k=j+1;k<=j+3;k++) if(N-k >= 1 && N-k <= 3){
        if(check(s, 0, i) && check(s, i, j) && check(s, j, k) && check(s, k, N)){
            string t = s.substr(0, i) + "." + s.substr(i, j-i) + "." + s.substr(j, k-j) + "." + s.substr(k, N-k);
            ans.push_back(t);
        }
    }
}

void dfs(int L, string s, int mask, int pos, int used){
    int i;
    
    if(pos == L){
        if(used == mask) func(s);
        return;
    }
    
    int pos2 = L - 1 - pos;
    if(pos2 < pos){
        if(mask != used) return;
        char c = s[pos2];
        dfs(L, s+c, mask, pos+1, used);
    } else {
        char c;
        REP(i,10) if(mask&(1<<i)){
            c = '0' + i;
            dfs(L, s+c, mask, pos+1, (used|(1<<i)));
        }
    }
}

int main(void){
    int N,x,mask=0,i;
    
    cin >> N;
    REP(i,N){
        cin >> x;
        mask |= (1<<x);
    }
    
    if(N <= 6) for(i=4;i<=12;i++) dfs(i, "", mask, 0, 0);
    
    cout << ans.size() << endl;
    REP(i,ans.size()) printf("%s\n", ans[i].c_str());
    
    return 0;
}