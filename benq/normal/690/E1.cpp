
#include <fstream>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define vi vector<int>

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)

#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000003;

int main() {
    string k = "100100001111111101010010010011110101110110110111011011111000100001000010100011011000000100101000011111001101010110111100010111010001000101111111110100000100101010100110110100100001110100011010111011011110110010001111";
    F0R(i,k.length()) {
        if (k[i] == '0') cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}