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


int n, a[216000], b[216000];
int main(){
    cin >> n;
    for(int i = 0;i < n;i++)cin >> a[i];
    int need = 0;
    for(int i = 0;i < n;i++){
        cin >> b[i];
        if(b[i] == 0)continue;
        need = max(need, i - (b[i] - 2));
    }
    bool ok = true;
    int p = n-1;
    if(b[p] == 0)ok = false;
    else{
        while(p > 0 && b[p] != 1 && b[p] - 1 == b[p-1])p--;
        if(b[p] != 1)ok = false;
    }
    if(ok){
        for(int i = 0;i < n;i++){
            if(b[i] == 1)break;
            if(b[i] == 0)continue;
            if(i+1 >= b[i] - b[n-1])ok = false;
        }
    }
    if(ok)cout << n - b[n-1] << endl;
    else cout << need + n << endl;
    return 0;
}