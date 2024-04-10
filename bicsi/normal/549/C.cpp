#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std;
typedef int var;

var Count[2];

string PL[] = {"Stannis", "Daenerys"};

int main() {

    #ifndef ONLINE_JUDGE
    freopen("debug.in", "r", stdin);
    freopen("debug.out", "w", stdout);
    #endif // ONLINE_JUDGE

    var n, k, a;

    cin>>n>>k;

    for(var i=1; i<=n; i++) {
        cin>>a;
        Count[a&1]++;
    }

    var total_ops = n-k;

    if(total_ops == 0) {
        if(Count[1] & 1) {
            cout<<PL[0];
        } else {
            cout<<PL[1];
        }
        return 0;
    }

    if(total_ops & 1) {
        //Ultimul e Stannis

        var ops = 2 * min(Count[0], Count[1]);
        if(ops > total_ops) {
            cout<<PL[0];
            return 0;
        }

        total_ops -= ops;
        Count[0] -= ops/2;
        Count[1] -= ops/2;

        if(Count[1] == 0) {
            cout<<PL[1];
            return 0;
        } else {
            Count[1] -= total_ops;
            if(Count[1] & 1) {
                cout<<PL[0];
                return 0;
            } else {
                cout<<PL[1];
                return 0;
            }
        }

    } else {
        //Ultimul e allalt
        var ops = 2 * min(Count[0], Count[1]) - 1;

        if(ops > total_ops) {
            cout<<PL[1];
            return 0;
        }

        total_ops -= ops;
        Count[0] -= ops/2;
        Count[1] -= ops/2;

        if(Count[1] <= 1) {
            cout<<PL[1];
            return 0;
        } else {
            Count[1] -= total_ops;
            if(Count[1] & 1) {
                cout<<PL[0];
                return 0;
            } else {
                cout<<PL[1];
                return 0;
            }
        }
    }

    return 0;
}