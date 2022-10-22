#include "list"
#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include "algorithm"
#include <iomanip>
#include "cmath"
#include "set"
#include <climits>
#define int long long
using namespace std;
int solve(string s, char l, char r){
    int res = 0;
    int counter = 0;
    for(auto i : s){
        if(i == l)
            counter++;
        if(i == r)
            if(counter){
                counter--;
                res++;
            }
    }
    return res;
}
void PolnalyubviTop(){
    string s;
    cin >> s;
    cout << solve(s, '(', ')') + solve(s, '[', ']') << '\n';
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        PolnalyubviTop();
    }
}