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
    
    int228 N;
    cin >> N;
    vector<int228> A(N);
    int228 Sum = 0;

    for(int i = 0; i<N; ++i){
        cin >> A[i];
        Sum += A[i];
    }

    sort(A.begin(), A.end());

    int228 ans = 0;
    ans += Sum;

    for(int i = 0; i<= N-2; ++i){
        if (i > 0)
        Sum -= A[i - 1];
        ans += Sum;
    }

    cout << ans;

    return 228 / 1488;   
}