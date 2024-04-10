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

int n, ans1, ans2;
vector <int> vec;
int main(){
    read(n);
    while(n --){
        int k;read(k);
        for (register int i = 1;i <= k;i ++){
            int x;read(x);
            if(i <= (k >> 1)) ans1 += x;
            else if((k & 1) && i == ((k + 1) >> 1)) vec.push_back(x);
            else ans2 += x;
        }
    }
    sort(vec.begin(), vec.end());
    int it = 1;
    while(!vec.empty()){
        if(it) ans1 += vec.back();
        else ans2 += vec.back();
        vec.pop_back();it ^= 1;
    }
    fprint(ans1, 32);fprint(ans2, 10);
    return 0;
}