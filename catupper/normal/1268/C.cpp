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

Int bit[220000];
Int pos[220000];
Int p[220000];
Int flip[220000];

void add(Int x){
    x++;
    while(x < 220000){
        bit[x]++;
        x += x & -x;
    }
}

Int sum(Int x){
    x++;
    Int res = 0;
    while(x){
        res += bit[x];
        x -= x &-x;
    }
    return res;
}

set<int> l, r;
Int lsum, rsum;

void add_num(int x){
    if(l.empty() || *prev(l.end()) > x){
        l.insert(x);
        lsum += x;
    }
    else{
        r.insert(x);
        rsum += x;
    }
    while(l.size() > r.size() + 1){
//        cout << l.size() << " " << r.size() << endl;
        auto largest = prev(l.end());
        r.insert(*largest);
        rsum += *largest;
        lsum -= *largest;
        l.erase(largest);
    }

    
    while(l.size() < r.size()){
        auto smallest = r.begin();
        l.insert(*smallest);
        lsum += *smallest;
        rsum -= *smallest;
        r.erase(smallest);
    }
}

Int aggregate(){
//    cout << l.size() << endl;
    Int mid = *prev(l.end());
    Int llen = l.size();
    Int ans = mid * llen - lsum - (llen-1)*llen / 2;
    Int rlen = r.size();
    ans += rsum - mid * rlen  - (rlen+1)*rlen / 2;
    return ans;
}

Int n;
int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        cin >> p[i];
    }
    for(int i = n-1;i >= 0;i--){
        pos[p[i]] = i;
        flip[p[i]] = sum(p[i]);
        add(p[i]);
    }
    Int flipsum = 0;
    for(int i = 1;i <= n;i++){
        flipsum += flip[i];
        add(pos[i]);
        add_num(pos[i]);
        printf("%lld ", flipsum + aggregate());
    }
    cout << endl;
    return 0;
}