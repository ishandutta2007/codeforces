#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <list>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
#define PCS cout << "Case #" << i << ":"
typedef long long ll;
int total=0;
inline void sol(int n){
    total+=n;
    if(n==1) return;
    for(int k=n/2;k>=1;k--){
        if(n%k==0){
            sol(k);
            break;
        }
    }
}
int main(){
    int n;
    cin >> n;
    sol(n);
    cout << total << endl;
    return 0;
}