#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define ll long long

map<int, ll> m1, m2;
ll ans = 0;
int x, n, k;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &x);
        if (x % k == 0){
            if ((x / k) % k == 0){
                if (m2.find(x / k) != m1.end()){
                    ans += m2[x / k];
                }
            }
            if (m1.find(x / k) != m1.end()){
                m2[x] += m1[x / k];
            }
        }
        m1[x]++;
    }
    printf("%I64d\n", ans);
  return 0;
}