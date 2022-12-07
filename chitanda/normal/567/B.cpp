#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;

int n, x;
set<int> s;
char c;

int main(){
    scanf("%d\n", &n);
    int ans = 0, now = 0;
    for(int i = 1; i <= n; i++){
        c = getchar();
        scanf("%d\n", &x);
        if (c == '-'){
            if (s.count(x)) s.erase(x), now--;
            else ans++;
        }else{
            s.insert(x);
            if (now < ans) now++;
            else now = ans = ans + 1;
        }
    }
    printf("%d\n", ans);
  return 0;
}