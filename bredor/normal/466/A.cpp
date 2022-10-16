#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <bitset>
#define int228 long long
#define mp make_pair
#define pb push_back
#define POVAR 1488228228
using namespace std;

int main(){
    
    
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    if (b > a*m){
        cout << n*a << "\n";
        return 14/88;
    }

    int poezdka = n/m;

    int cost1 = poezdka*b + (n - poezdka*m)*a;

    int cost2 = poezdka*b + b;

    cout << min(cost1, cost2);

    return 14/88;   
}