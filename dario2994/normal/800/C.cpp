#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;

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

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_vec(x) clog << #x << ": " << print_iterable(x.begin(), x.end(), -1) << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x) 
    #define dbg_vec(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

//Used implicitly during the calculation of gcd
ULL gcdCalculate(ULL x, ULL y) {
	if (x == 0) return y;
	return gcdCalculate(y%x, x); 
}

//Return the gcd of x, y 
//gcd(-10, 15)= 5
ULL gcd(LL x, LL y) {
	if (x<0) x =-x;
	if (y<0) y =-y;
	if (x>y) return gcdCalculate(y, x);
	return gcdCalculate(x, y);
}

//Return the inverse of n modulo m. (doesn't check whether they are coprime)
//inverse(5, 9)= 2; inverse(3, 16)= 11
ULL inverse(ULL n, ULL m) {
	if (n == 1) return 1;
	ULL y = inverse(m%n, n);
	return m-((m*y-1)/n)%m;
}

const int MAXN = 200000;

int N, M;
bool forb[MAXN];

map<int, vector<int>> divis;
map<int, int> din;
map<int, int> chosen;
set<int> all_div;

int main() {
    ios::sync_with_stdio(false);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        forb[x] = 1;
    }


    if (!forb[0]) divis[M].push_back(0);
    all_div.insert(M);
    for (int i = 1; i < M; i++) {
        int d = gcd(i, M);
        all_div.insert(d);
        if (!forb[i]) divis[d].push_back(i);
    }
    int first_div;
    int res = 0;
    for (auto it = all_div.rbegin(); it != all_div.rend(); it++) {
        int num = *it;
        chosen[num] = -1;
        for (auto d : all_div) {
            if (d == num or num == 0 or d%num) continue;
            if (MaxPlace(din[num], din[d])) {
                chosen[num] = d;
            }
        }
        din[num] += divis[num].size();
        if (MaxPlace(res, din[num])) {
            first_div = num;
        }
    }
    cout << din[1] << "\n";
    int curr = 1;
    int curr_div = 1;
    while (first_div != -1) {
        for (int a : divis[first_div]) {
            LL d1 = curr_div;
            LL x = curr/d1;
            LL d2 = first_div;
            LL y = a/d2;
            
            LL val = d2/d1;
            val *= y;
            val %= (LL)M;
            val *= inverse(x, M/d1);
            val %= (LL)M;
            cout << val << " ";
            curr = a;
            curr_div = first_div;
        }
        first_div = chosen[first_div];
    }
}