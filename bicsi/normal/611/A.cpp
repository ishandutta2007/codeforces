#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000005

typedef unsigned long long ull;

int no;
string bs, str;

int start;
int Cnt[20];

int main() {


    cin>>no>>bs>>str;


    if(str == "week") {
        int start = 4;
        no -= 1;

        for(int i=1; i<=366; i++) {
            Cnt[start] += 1;
            start += 1;
            start %= 7;
        }

        cout << Cnt[no];
    } else {
        if(no <= 29) {
            cout << 12;
        } else if(no <= 30) {
            cout << 11;
        } else {
            cout << 7;
        }
    }

    return 0;
}