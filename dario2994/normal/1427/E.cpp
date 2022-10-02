#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define SZ(x) ((int)((x).size()))

template <typename T1, typename T2>
string print_iterable(T1 begin_iter, T2 end_iter, int counter) {
    bool done_something = false;
    stringstream res;
    res << "[";
    for (; begin_iter != end_iter and counter; ++begin_iter) {
        done_something = true;
        counter--;
        res << *begin_iter << ", ";
    }
    string str = res.str();
    if (done_something) {
        str.pop_back();
        str.pop_back();
    }
    str += "]";
    return str;
}

vector<int> SortIndex(int size, std::function<bool(int, int)> compare) {
    vector<int> ord(size);
    for (int i = 0; i < size; i++) ord[i] = i;
    sort(ord.begin(), ord.end(), compare);
    return ord;
}

template <typename T>
bool MinPlace(T& a, const T& b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template <typename T>
bool MaxPlace(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template <typename S, typename T>
ostream& operator <<(ostream& out, const pair<S, T>& p) {
    out << "{" << p.first << ", " << p.second << "}";
    return out;
}

template <typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {
    out << "[";
    for (int i = 0; i < (int)v.size(); i++) {
        out << v[i];
        if (i != (int)v.size()-1) out << ", ";
    }
    out << "]";
    return out;
}

template<class TH>
void _dbg(const char* name, TH val){
    clog << name << ": " << val << endl;
}
template<class TH, class... TA>
void _dbg(const char* names, TH curr_val, TA... vals) {
    while(*names != ',') clog << *names++;
    clog << ": " << curr_val << ", ";
    _dbg(names+1, vals...);
}

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
    #define dbg_arr(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg(...)
    #define dbg_arr(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

LL Inverse(LL n, LL m) {
    n %= m;
    if (n <= 1) return n; // Handles properly (n = 0, m = 1).
    return m - ((m * Inverse(m, n) - 1) / n);
}


vector<ULL> A;
vector<char> op;
vector<ULL> B;

void add_op(ULL a, char o, ULL b) {
    if (a == 0 or b == 0) return;
    A.push_back(a);
    op.push_back(o);
    B.push_back(b);
}

ULL xxor(ULL a, ULL b) {
    add_op(a, '^', b);
    return a^b;
}

ULL sum(ULL a, ULL b) {
    add_op(a, '+', b);
    return a+b;
}

ULL mul(ULL a, ULL n) {
    ULL pot = a;
    ULL curr = 0;
    while (n > 0) {
        if (n%2) curr = sum(curr, pot);
        pot = sum(pot, pot);
        n /= 2;
    }
    return curr;
}

int main() {
    ULL x;
    cin >> x;
    while (x != 1) {
        for (ULL n = 2; ; n *= 2) {
            sum((n/2)*x, (n/2)*x);
            if (((n*x)^x)%x == 0) continue;
            ULL y = xxor(n*x, x);
            ULL g = __gcd(x, y);
            ULL a = mul(x, Inverse(x/g, y/g));
            ULL b = mul(y, (a-g)/y);
            ULL pot = 1<<20; // must be larger than g
            ULL q = (pot- b%pot) * Inverse(x, pot) % pot;
            ULL c = mul(x, q);
            x = xxor(sum(a, c), sum(b, c));
            break;
        }
    }

    cout << A.size() << "\n";
    for (int i = 0; i < (int)A.size(); i++)
        cout << A[i] << " " << op[i] << " " << B[i] << "\n";
}