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

Int a[220000];
Int b[220000];
Int n, k;

int main(){
    cin >> n >> k;
    for(int i = 1;i <= n;i++){
        scanf("%1lld", a + i);
        b[i] = a[i];
    }

    for(int i = 1;i <= n;i++){
        if(i + k <= n){
            a[i+k] = a[i];
        }
    }

    int x = 0;
    while(x <= n && a[x] == b[x])x++;
    if(x == n+1 || a[x] > b[x]){
        cout << n << endl;
        for(int i = 1;i <= n;i++)printf("%lld", a[i]);
        cout << endl;
        return 0;
    }
    
    a[k]++;
    for(int i = k;i > 0;i--){
        a[i-1] += a[i] / 10;
        a[i] %= 10;
    }
    if(a[0] == 0){
        for(int i = 1;i <= n;i++){
            if(i + k <= n){
                a[i+k] = a[i];
            }
        }

        cout << n << endl;
        for(int i = 1;i <= n;i++)printf("%lld", a[i]);
        cout << endl;
    }
    else{
        n++;
        cout << n << endl;
        for(int i = 0;i < n;i++){
            if(i + k < n){
                a[i+k] = a[i];
            }
        }

        for(int i = 0;i < n;i++)printf("%lld", a[i]);
        cout << endl;
    }
    return 0;
}