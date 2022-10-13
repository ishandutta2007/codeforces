#include <iostream>
#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;
typedef int var;

var DEG[50000], I[50000];

#define LIM 5000

vector<pair<var, var>> SOL;

var TAG[20000][2];

bool canDo(var nodes) {
    if(nodes < 0)
        return true;

    if(DEG[I[nodes]] < 0)
        return false;

    var deg = DEG[I[1]];
    if(deg > nodes-1) return false;

    for(var j=2; j<=1+deg; j++) {
        SOL.push_back(make_pair(I[1], I[j]));
        DEG[I[j]]--;
    }

    DEG[I[1]] = 0;


    sort(I+1, I+nodes+1, [](var a, var b) {
            return DEG[a] > DEG[b];
         });

    while(DEG[I[nodes]] == 0 && nodes >= 0)
        nodes--;

    return canDo(nodes);
}

int main() {
    //freopen("debug.in", "r", stdin);
    //freopen("debug.out", "w", stdout);

    var k;
    cin>>k;

    if(k == 1) {
        cout<<"YES\n2 1\n1 2";
        return 0;
    }

    if(k % 2 == 0) {
        cout << "NO";
        return 0;
    }

    var nodes;

    for(nodes=k; nodes<=LIM; nodes++) {
        for(var i=1; i<=nodes; i++) {
            DEG[i] = k;
            I[i] = i;
        }
        DEG[nodes]--;

        if(canDo(nodes))
            break;
        else SOL.clear();
    }

    if(nodes > LIM) {
        cout<<"NO";
        return 0;
    }

    for(var i=1; i<=nodes; i++) {
        TAG[i][0] = i;
        TAG[i][1] = i + nodes;
    }

    cout<<"YES\n"<<nodes*2<<" "<<nodes*k<<'\n'<<TAG[nodes][0]<<" "<<TAG[nodes][1]<<'\n';
    for(auto sol : SOL) {
        cout<<TAG[sol.first][0] << " " << TAG[sol.second][0]<<'\n';
        cout<<TAG[sol.first][1] << " " << TAG[sol.second][1]<<'\n';
    }



    return 0;
}