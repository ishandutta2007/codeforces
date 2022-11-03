#include <bits/stdc++.h>
using namespace std;

const long long kMaxB = 1e6;

long long A, B;
int n;

bool Check(long long l, long long r, long long t, long long m)
{
    return A + B * (r - 1) <= t && 
        A * (r - l + 1) + B * (l - 1 + r - 1) * (r - l + 1) / 2 <= t * m;
}

long long GetAnswer(long long l, long long t, long long m)
{
    long long bl = 1;
    long long br = kMaxB;
    long long ans = -1;
    while (bl <= br) {
        long long bm = (bl + br) >> 1;
        
        if (Check(l, l + bm - 1, t, m)) {
            ans = bm + l - 1;
            bl = bm + 1;
        } else {
            br = bm - 1;
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B >> n;
    for (int i = 0; i < n; ++i) {
        long long l, t, m;
        cin >> l >> t >> m;
        cout << GetAnswer(l, t, m) << endl;
    }
    
    return 0;
}