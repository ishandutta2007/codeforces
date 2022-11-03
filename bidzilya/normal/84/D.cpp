#include <bits/stdc++.h>
using namespace std;

int n;
long long k;
vector<int> a;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    a.resize(n);
    long long sm = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sm += a[i];
    }
    
    if (k > sm) {
        cout << -1 << endl;
        return 0;
    }
    
    int bl = 0;
    int br = 1e9;
    while (bl <= br) {
        int bm = (bl + br) >> 1;
        
        long long ck = k - 1LL * bm * n;
        for (int i = 0; i < n; ++i) {
            int x = a[i] - bm;
            if (x < 0) {
                ck += -x;
            }
        }
        
        if (ck < 0) {
            br = bm - 1;
        } else {
            deque<pair<int, int> > t;
            for (int i = 0; i < n; ++i) {
                if (a[i] - bm > 0) {
                    t.push_back(make_pair(i, a[i] - bm));
                }
            }
            
            if (t.empty()) {
                bl = bm + 1;
                continue;
            }
            
            for (int itr = 0; itr <= n; ++itr) {
                if (ck == 0) {
                    for (int i = 0; i < (int) t.size(); ++i) {
                        cout << t[i].first + 1 << " ";
                    }
                    cout << endl;
                    return 0;
                }
                
                int id = t.front().first;
                int val = t.front().second;
                
                t.pop_front();
                
                --val;
                --ck;
                
                if (val > 0) {
                    t.push_back(make_pair(id, val));
                }
            }
            
            bl = bm + 1;
        }
    }
}