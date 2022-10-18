#include <bits/stdc++.h>
using namespace std;

template <typename T>
inline void read(T &x){
    x = 0;int fu = 1;
    char c = getchar();
    while(c > 57 || c < 48){
        if(c == 45) fu = -1;
        c = getchar();
    }
    while(c <= 57 && c >= 48){
        x = (x << 3) + (x << 1) + c - 48;
        c = getchar();
    }
    x *= fu;
}
template <typename T>
inline void fprint(T x){
    if(x < 0) putchar(45), x = -x;
    if(x > 9) fprint(x / 10);
    putchar(x % 10 + 48);
}
template <typename T>
inline void fprint(T x, char ch){
    fprint(x);putchar(ch);
}
inline char next_char(){
    char ch = getchar();
    while(ch == 9 || ch == 10 || ch == 32) ch = getchar();
    return ch;
}
typedef long long LL;
int n;
LL w;
pair <LL, int> a[200005];
vector <int> ans;
int main(){
    int T;read(T);
    while(T --){
        read(n);read(w);
        for (register int i = 1;i <= n;i ++) read(a[i].first), a[i].second = i;
        sort(a + 1, a + n + 1);
        while(n && a[n].first > w) n --;
        if(!n) {
            printf("-1\n");
            continue;
        }
        if(a[n].first >= (w >> 1) + (w & 1)) {
            printf("1\n%d\n", a[n].second);
            continue;
        }
        LL sig = 0;
        for (register int i = 1;i <= n;i ++){
            sig += a[i].first;
        }
        if(sig < (w >> 1) + (w & 1)) {
            printf("-1\n");
            continue;
        }
        sig = 0;
        for (register int i = 1;i <= n;i ++){
            sig += a[i].first;
            ans.push_back(a[i].second);
            if(sig >= (w >> 1) + (w & 1)){
                sort(ans.begin(), ans.end());
                reverse(ans.begin(), ans.end());
                fprint(ans.size(), 10);
                while(!ans.empty()){
                    fprint(ans.back(), 32);
                    ans.pop_back();
                }
                putchar(10);
                break;
            }
        }
    }
}