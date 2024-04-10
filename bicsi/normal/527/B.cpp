//#include<fstream>
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
typedef int var;

#define fin cin
#define fout cout

//ifstream fin("date.in");
//ofstream fout("date.out");

#define MAXN 200001
#define mp make_pair

string s1, s2;
vector<var> Bad;

unordered_map<var, var> G[500];

var Contains[500];

int main() {
    var n;
    fin>>n;
    fin>>s1>>s2;
    bool foundSol = 0;
    var sol1, sol2;

    for(var i=0; i<n; i++) {
        if(s1[i] != s2[i]) {
            Bad.push_back(i);
            if(G[(int)s2[i]][(int)s1[i]]) {
                foundSol = 1;
                sol1 = G[(int)s2[i]][(int)s1[i]];
                sol2 = i+1;
            }
            G[(int)s1[i]][(int)s2[i]] = i+1;
            Contains[(int)s2[i]] = i+1;
        }
    }

    if(foundSol) {
        fout<<Bad.size() - 2<<'\n'<<sol1<<" "<<sol2;
        return 0;
    }

    for(auto i : Bad) {
        char c = s1[i];
        if(Contains[c]) {
            var v1 = min(i+1, Contains[c]),
                v2 = max(i+1, Contains[c]);
            fout<<Bad.size() - 1 << '\n' << v1 << " " << v2;
            return 0;
        }
    }

    fout<<Bad.size()<<"\n-1 -1";


}