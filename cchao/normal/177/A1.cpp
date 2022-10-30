#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
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
typedef long long ll;
int graph[110][110];
int main(){
    int tt,tol=0;
    cin >> tt;
    memset(graph,0,sizeof(graph));
    REP(j,tt)
        REP(k,tt){
            cin >> graph[j][k];
        }
    int mid = (tt-1)/2;
    REP(k,tt){
        tol+=graph[k][k];
        graph[k][k]=0;
        tol+=graph[mid][k];
        graph[mid][k]=0;
        tol+=graph[k][mid];
        graph[k][mid]=0;
        tol+=graph[k][tt-k-1];
        graph[k][tt-k-1]=0;
    }
    cout << tol;
    return 0;
}