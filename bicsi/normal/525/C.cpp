#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
typedef int64_t var;

#define fin cin
#define fout cout

vector<var> V;
vector<var> Pairs;

int main() {

    //freopen("3.in", "r", stdin);
    //freopen("3.out", "w", stdout);

    var n, a;
    fin>>n;

    for(var i=1; i<=n; i++) {
        fin>>a;
        V.push_back(a);
    }
    sort(V.rbegin(), V.rend());

    for(var i=0; i<V.size(); i++) {
        if(V[i] == V[i+1]) {
            Pairs.push_back(V[i]);
            i++;
        } else if(V[i] == V[i+1] + 1) {
            Pairs.push_back(V[i+1]);
            i++;
        }
    }

    int64_t S = 0;
    for(var i=0; i+1<Pairs.size(); i+=2) {
        S += 1LL*Pairs[i]*Pairs[i+1];
    }
    fout<<S;

    return 0;
}