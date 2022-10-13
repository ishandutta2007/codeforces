#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
typedef int var;

#define fin cin
#define fout cout

var Has[50];

int main() {

    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);

    var n;
    fin>>n;
    var nr = 0;
    char t;
    for(var i=1; i<=n-1; i++) {
        fin>>t;
        Has[t-'a']++;
        fin>>t;
        if(Has[t-'A']) Has[t-'A']--;
        else nr++;
    }

    fout<<nr;

    return 0;
}