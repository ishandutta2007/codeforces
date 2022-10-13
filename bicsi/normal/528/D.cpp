#include <bits/stdc++.h>

using namespace std;
typedef int var;
unordered_map<char, var> Map;

#define MAXN 200005

bitset<MAXN> Ans;
bitset<MAXN> Text[4];

var Add[4][MAXN];

char T[MAXN], P[MAXN];

int main() {
    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    Map['A'] = 0; Map['C'] = 1; Map['G'] = 2; Map['T'] = 3;

    var t, p, k;
    char c;

    cin>>t>>p>>k;
    cin>>T>>P;

    for(var i=0; i<t; i++) {
        c = Map[T[i]];
        Add[c][max(0, i-k)] ++;
        Add[c][min(t, i+k+1)] --;
        Ans[i] = 1;
    }

    for(var d=0; d<4; d++) {
        for(var i=0; i<t; i++) {
            Add[d][i+1] += Add[d][i];
            if(Add[d][i]) Text[d][i] = 1;
        }
    }

    for(var i=0; i<p; i++)
        P[i] = Map[P[i]];

    for(var i=0; i<p; i++) {
        Ans &= (Text[P[i]] >> i);
    }


    cout<<Ans.count();

    return 0;
}