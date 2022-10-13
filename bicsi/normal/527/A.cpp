#include<fstream>
#include<iostream>

using namespace std;
typedef int64_t var;

#define fin cin
#define fout cout

var sol(var a, var b) {
    if(b == 0) return 0;
    return a/b + sol(b, a%b);
}

int main() {
    var a, b;
    fin>>a>>b;
    if(a < b) swap(a, b);
    fout<<sol(a, b);
}