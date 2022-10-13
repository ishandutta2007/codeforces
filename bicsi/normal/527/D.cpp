//#include<fstream>
#include<iostream>
#include<algorithm>

using namespace std;
typedef int var;

#define fin cin
#define fout cout

//ifstream fin("date.in");
//ofstream fout("date.out");

#define MAXN 300001
#define mp make_pair

var MIN[MAXN];
var SOL[MAXN];

vector<pair<var, var> >V;

int main() {

    var n, x, w;
    fin>>n;
    V.push_back(mp(-2, 0));
    for(var i=1; i<=n; i++) {
        fin>>x>>w;
        V.push_back(mp(x, w));
    }
    sort(V.begin(), V.end());

    for(var i=1; i<=n; i++) {
        MIN[i] = 2000000000;
    }

    var mlsc = 0;

    for(var i=1; i<=n; i++) {
        var xc = V[i].first, wc = V[i].second;

        var lsc;

        var t = 0, poz = 0;

        for(t = 1; t<=mlsc; t<<=1);
        for(t>>=1; t; t>>=1) {
            if(poz+t <= mlsc && xc-wc >= MIN[poz+t]) {
                poz += t;
            }
        }
        SOL[i] = poz + 1;
        MIN[poz + 1] = min(MIN[poz + 1], wc + xc);
        mlsc = max(mlsc, poz + 1);
    }

    fout << mlsc;

    return 0;
}