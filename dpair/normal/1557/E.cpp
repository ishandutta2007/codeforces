#include <bits/stdc++.h>

int pos;
inline std::string move(int x, int y) {
    printf("%d %d\n", x, y); fflush(stdout); pos = y;
    std::string ret; std::cin >> ret; return ret;
}

bool judge(const int x) {
    for (int i = 1 + (pos == 1);i <= 8;++ i) {
        std::string s = move(x, i);
        if(s == "Done") return 1;
        if(s[0] == 'D') return 0;
        if(s[0] == 'U') return judge(x);
    }
    return 0;
}

inline void work() {
    pos = 1;
    for (int i = 1;i <= 8;++ i) {
        if(move(i, pos) == "Done") return ;
        if(judge(i)) return ;
    }
}

int main() {
    int T; scanf("%d", &T);
    while(T --) work();
}