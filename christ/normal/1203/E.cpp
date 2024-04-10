#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int freq[150005];
bool taken[150005];
int main() {
    int n,a;
    scanf ("%d",&n);
    for (int i = 1; i <= n; i++) {
        scanf ("%d",&a);
        freq[a]++;
    }
    for (int i = 1; i <= 150000; i++) if (freq[i]){
        freq[i] += taken[i];
        if (i > 1 && !taken[i-1]) taken[i-1] = 1, freq[i]--;
        if (freq[i] > 1) taken[i+1] = 1, freq[i]--;
        if (!taken[i] && freq[i]) taken[i] = 1;
    }
    int cnt = 0;
    for (int i = 1; i <= 150001; i++) if (taken[i]) cnt++;
    printf ("%d\n",cnt);
    return 0;
}