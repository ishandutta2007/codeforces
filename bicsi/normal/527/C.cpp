#include<fstream>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;
typedef int var;

#define fin cin
#define fout cout
//ifstream fin("date.in");
//ofstream fout("date.out");

typedef pair<char, var> pci;
stack<pci> St;

#define MAXN 300005
#define mp make_pair



var Parent[2][MAXN], Rank[2][MAXN], L[2][MAXN];
var N[2];
var MAX[2];
var Cut[2][MAXN];
stack<long long> Sol;

var Find(var t, var i) {
    if(Parent[t][i] == 0) return i;
    Parent[t][i] = Find(t, Parent[t][i]);
    return Parent[t][i];
}

void Union(var t, var t1, var t2) {
    t1 = Find(t, t1);
    t2 = Find(t, t2);

    if(Rank[t][t1] < Rank[t][t2]) {
        Parent[t][t1] = t2;
        L[t][t2] += L[t][t1];
    } else {
        Parent[t][t2] = t1;
        L[t][t1] += L[t][t2];
        Rank[t][t1] += (Rank[t][t1] == Rank[t][t2]);
    }
}

int main() {

    var w, h, n;

    fin>>w>>h>>n;
    //0->h
    //1->w

    N[0] = h;
    N[1] = w;

    char type;
    var a;

    while(n--) {
        fin>>type>>a;
        if(type == 'H') {
            Cut[0][a+1] = 1;
        } else {
            Cut[1][a+1] = 1;
        }

        St.push(mp(type, a));
    }

    for(var t=0; t<2; t++) {
        for(var i=1; i<=N[t]; i++) {
            L[t][i] = 1;
        }
    }

    for(var t=0; t<2; t++) {
        for(var i=1; i<N[t]; i++) {
            if(!Cut[t][i+1]) {
                Union(t, i, i+1);
            }
            MAX[t] = max(MAX[t], L[t][Find(t, i)]);
        }
    }


    var t;
    while(!St.empty()) {
        pci top = St.top();
        St.pop();

        Sol.push(1LL*MAX[0]*MAX[1]);

        if(top.first == 'H') {
            t = 0;
        } else {
            t = 1;
        }


        Union(t, top.second, top.second + 1);
        MAX[t] = max(MAX[t], L[t][Find(t, top.second)]);
    }

    while(!Sol.empty()) {
        fout<<Sol.top()<<'\n';
        Sol.pop();
    }

    return 0;
}