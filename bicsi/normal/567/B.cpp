#include <bits/stdc++.h>

using namespace std;
typedef int var;
typedef pair<var, var> Pair;

unordered_map<var, bool> In;
var Total[5000];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    #endif // ONLINE_JUDGE

    int n;
    char c;
    int no;
    cin>>n;

    for(int i=1; i<=n; i++) {
        cin>>c>>no;
        if(c == '+') {
            In[no] = 1;
            Total[i] = Total[i-1] + 1;
        } else {
            if(In[no] == 1) {
                In[no] = 0;
            } else {
                for(int j=0; j<i; j++)
                    Total[j]++;
            }

            Total[i] = Total[i-1] - 1;
        }
    }

    int best = -1;
    for(int i=0; i<=n; i++) {
        best = max(best, Total[i]);
    }
    cout<<best;

    return 0;
}