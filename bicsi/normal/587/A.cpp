#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int Freq[5000000];

void Read(int &a) {
    char c;
    for(c = getchar(); !isdigit(c); c = getchar());
    for(a = 0; isdigit(c); c = getchar())
        a = a * 10 + c - '0';
}

int main() {
    int n, val;
    Read(n);

    int M = 0;
    for(int i=1; i<=n; i++) {
        Read(val);
        M = max(M, val);
        Freq[val]++;
    }

    int cnt = 0;
    for(int i=0; i<=M || Freq[i] > 0; i++) {
        if(Freq[i] % 2)
            cnt++;
        Freq[i+1] += Freq[i] / 2;
    }

    cout<<cnt;
    return 0;
}