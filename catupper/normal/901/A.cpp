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

int p, h;
int dep[220000];
int dep_first[220000];
int a[220000];
int parent[220000];
int main(){
    cin >> h;
    int ambiguous = -1;
    p = 1;
    for(int i = 0;i <= h;i++){
        cin >> a[i];
        dep_first[i] = p;
        for(int j = 0;j < a[i];j++){
            if(i)parent[p] = dep_first[i-1];
            dep[p++] = i;
        }
        if(i && a[i] > 1 && a[i-1] > 1)ambiguous = i;

    }
    if(ambiguous==-1){
        cout << "perfect" << endl;
        return 0;
    }
    cout << "ambiguous" << endl;
    for(int i = 1;i < p;i++){
        cout << parent[i] <<  " ";
    }cout << endl;
    parent[dep_first[ambiguous] + 1] = dep_first[ambiguous-1] + 1;
    for(int i = 1;i < p;i++){
        cout << parent[i] <<  " ";
    }cout << endl;    
    return 0;
}