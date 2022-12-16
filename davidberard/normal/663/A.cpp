#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    string s;
    vector<int> vals;
    vals.push_back(0);
    int deficit = 0;
    int free = 1;
    while(true) {
        cin >> s;
        assert(s[0] == '?');
        cin >> s;
        if(s[0] == '=') {
            break;
        }
        if(s[0] =='-') {
            ++deficit;
            vals.push_back(-1);
        } else {
            ++ free;
            vals.push_back(0);
        }
    }
    int N;
    cin >> N;
    if(N*free - deficit >= N && free-deficit*N <= N) {
        cout << "Possible\n";
        int avail = N+deficit-free;
        int nxt = max(0, min(avail, N-1));
        avail -= nxt;
        cout << nxt+1 << " ";
        for(int i=1;i<vals.size();++i) {
            if(vals[i] == -1) {
                int nxt = max(0, min(-avail, N-1));
                avail += nxt;
                cout << "- " << 1+nxt << " ";
            } else {
                int nxt = max(0, min(avail, N-1));
                avail -= nxt;
                cout << "+ " << nxt+1 << " ";
            }
        }
        cout << "= " << N << endl;
    }
    else {
        cout << "Impossible\n";
    }

    return 0;
}