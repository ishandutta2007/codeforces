#include "bits/stdc++.h"

#define all_of(x) std::begin(x), std::end(x)
#ifdef _GLIBCXX_DEBUG
    #define debug(x) cerr << #x << ": " << x << endl
#else
    #define debug(x) 
#endif

using namespace std;

using LL = long long;

template<typename T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << "[";
    for(const auto& x : v) {
        out << x << ", ";
    }
    return out << "]";
}
template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for(auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename S, typename T>
ostream& operator << (ostream& out, const pair<S, T>& p) {
    return out << "{" << p.first << ", " << p.second << "}";
}

void extended_gcd(LL a, LL b, LL& x, LL& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return;
    }
    LL x1, y1;
    extended_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
}

template<typename T>
void print_multiples(LL n, LL k, T& moves) {
    if(k == 1) {
        return;
    }
    if(k % 2 == 0) {
        moves.emplace_back("+", n, n);
        print_multiples(2 * n, k / 2, moves);
    } else {
        print_multiples(n, k - 1, moves);
        moves.emplace_back("+", n, n * (k - 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    LL n;
    cin >> n;
    vector<tuple<string, LL, LL>> moves;
    /*for(LL k = 1; k < 1000; ++k) {
        moves.emplace_back("+", n, n * k);
    }*/
    while(true) {
        /*LL a = 1 + (rand() % 999), b = 1 + (rand() % 999);
        LL c = 1 + (rand() % 999), d = 1 + (rand() % 999);
        LL x, y;
        if(rand() % 2) {
            x = n * a;
        } else {
            x = (n * a) ^ (n * b);
        }
        y = (n * c) ^ (n * d);
        if(x == 0 or y == 0) {
            continue;
        }
        debug(x);
        debug(y);*/
        LL a = n + 1 + (rand() % 1000);
        LL x = n, y = n ^ (n * a);
        if(__gcd(x, y) == 1) {
            debug(x);
            debug(y);
            print_multiples(n, a, moves);
            moves.emplace_back("^", n, n * a);
            LL h, k;
            extended_gcd(x, y, h, k);
            if(h < 0) {
                swap(x, y);
                swap(h, k);
            }
            k = -k;
            if(double(x) * double(h) > 4e18) {
                continue;
            }
            print_multiples(x, h, moves);
            print_multiples(y, k, moves);
            LL u = x * h, v = y * k;
            assert(u == v + 1);
            if(u % 2 == 0) {
                moves.emplace_back("+", u, n);
                moves.emplace_back("+", v, n);
                u += n;
                v += n;
            }
            moves.emplace_back("^", u, v);
            break;
        }
    }
    
    cout << moves.size() << "\n";
    for(auto& [s, x, y] : moves) {
        cout << x << " " << s << " " << y << "\n";
    }
    
    return 0;
}