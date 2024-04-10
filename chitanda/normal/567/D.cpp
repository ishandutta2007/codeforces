#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int tot, b[200100], x, n, a, k, m;
multiset<int> s;

int main(){
    scanf("%d%d%d", &n, &k, &a);  a++;
    s.insert(1); s.insert(n);
    b[1] = 1; b[n] = 2;
    tot = (n + 1) / a;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++){
        scanf("%d", &x);
        set<int>::iterator it = s.lower_bound(x);
        if (b[*it] == 2){
            if (it != s.end()){
                set<int>::iterator it1 = it; it1++;
                if (*it1 == *it) it++;
            }
            int r = *it;
            it--;
            int l = *it;
            tot -= (r - l + 2) / a;
            tot += (r - x + 1) / a;
            tot += (x - l + 1) / a;
            if (x < r - 1) b[x + 1] = 1;
            if (x > l) b[x - 1] = 2;
            if (x < r) s.insert(x + 1); else s.erase(r);
            if (x > l) s.insert(x - 1); else s.erase(l);
        }else if (*it == x){
            int l = *it;
            it++;
            int r = *it;
            tot -= (r - l + 2) / a;
            tot += (r - x + 1) / a;
            tot += (x - l + 1) / a;
            if (x < r - 1) b[x + 1] = 1;
            if (x > l) b[x - 1] = 2;
            if (x < r) s.insert(x + 1); else s.erase(r);
            if (x > l) s.insert(x - 1); else s.erase(l);
        }
        if (tot < k) { printf("%d", i); break; }
    }
    if (tot >= k) printf("%d", -1);
  return 0;
}