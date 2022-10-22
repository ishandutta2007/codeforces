#include "bits/stdc++.h"

using namespace std;

map<string, char> mapp = {
        {"10010", 'a'},
        {"11020", 'b'},
        {"20011", 'c'},
        {"21012", 'd'},
        {"11011", 'e'},
        {"21021", 'f'},
        {"22022", 'g'},
        {"12021", 'h'},
        {"11011", 'i'},
        {"12012", 'j'},
        {"10120", 'k'},
        {"11130", 'l'},
        {"20121", 'm'},
        {"21122", 'n'},
        {"11121", 'o'},
        {"21131", 'p'},
        {"22132", 'q'},
        {"12131", 'r'},
        {"11121", 's'},
        {"12122", 't'},
        {"10221", 'u'},
        {"11231", 'v'},
        {"12113", 'w'},
        {"20222", 'x'},
        {"21223", 'y'},
        {"11222", 'z'},
};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int a, b, c, d, e;
        scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
        putchar(mapp[to_string(a) + to_string(b) + to_string(c) + to_string(d) + to_string(e)]);
    }
    return 0;
}