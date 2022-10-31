#include <iostream>

using namespace std;

int tl=0, tr=0;
const int N = 1e5+5;
int l[N],r[N];

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        tl += l[i];
        tr += r[i];
    }
    int diff = abs(tl-tr);
    int cur = 0;
    for(int i = 0; i < n; ++i) {
        int score = abs((tl-l[i]+r[i]) - (tr-r[i]+l[i]));
        if(score > diff) {
            diff = score;
            cur = i+1;
        }
    }
    cout << cur << "\n";
}