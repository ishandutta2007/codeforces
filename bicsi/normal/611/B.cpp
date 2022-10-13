#include <bits/stdc++.h>

using namespace std;

#define MAXN 5000005

typedef unsigned long long ull;

vector<ull> Nums;

int main() {

    for(int no=1; no<64; no++) {
        for(int poz=0; poz<no-1; poz++) {
            unsigned long long x = (1LL << no) - 1LL;
            x ^= (1LL << poz);
            Nums.push_back(x);
        }
    }

    //for(int i=0; i<10; i++) cout << Nums[i] << " ";

    ull a, b;
    cin >> a >> b;



    int total = 0;

    for(auto x : Nums) {
        if(x >= a && x <= b)
            total += 1;
    }

    cout << total;

    return 0;
}