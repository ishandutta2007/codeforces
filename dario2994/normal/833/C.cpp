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

#define INF 1<<30
#define eps 1e-9

#if DEBUG && !ONLINE_JUDGE
    ifstream input_from_file("input.txt");
    #define cin input_from_file

    #define dbg_var(x) clog << #x  << ": " << x << endl;
    #define dbg_array(x, len) clog << #x << ": " << print_iterable(x, x+len, -1) << endl;
#else
    #define dbg_var(x)
    #define dbg_array(x, len)
#endif

///////////////////////////////////////////////////////////////////////////
//////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
///////////////////////////////////////////////////////////////////////////

// This should not compile if used.
const int MAXN = -1;

LL pot10[20];
LL JustSort(int len, vector<int>& seq) {
    LL res = 0;
    for (LL i = 9; i >= 1; i--) {
        while (seq[i] > 0) res = 10ll*res + i, len--, seq[i]--;
    }
    while (len > 0) res *= 10ll, len--;
    return res;
}

LL biggest(const vector<LL>& UP, int index, vector<int>& seq, int sum) {
    if (index + 1 < sum) return -1;
    if (index == 0) {
        if (sum == 0) return 0;
        if (sum == 1) {
            for (int i = 1; i <= UP[index]; i++) {
                if (seq[i] > 0) return i;
            }
            return -1;
        }
    }
    if (seq[UP[index]] > 0) {
        seq[UP[index]]--;
        LL ans = biggest(UP, index-1, seq, sum-1);
        if (ans != -1) return ans + pot10[index] * UP[index];
        seq[UP[index]]++;
    }
    if (UP[index] == 0) {
        return biggest(UP, index-1, seq, sum);
    }

    for (int i = UP[index]-1; i > 0; i--) {
        if (seq[i] > 0) {
            seq[i]--;
            return ((LL)i)*pot10[index] + JustSort(index, seq);
        }
    }
    if (sum > index) return -1;
    return JustSort(index, seq);
}

LL total = 0;
LL L, R, R2;
vector<LL> bb;

void generate(int max_len, int cifra, int sum, vector<int>& cc) {
    if (cifra == 10) return;
    for (int i = 1; i <= max_len-sum; i++) {
        cc[cifra] = i;
        vector<int> copia = cc;
        LL maybe = biggest(bb, (int)bb.size()-1, copia, sum + i);
        if (maybe != -1 and maybe >= L) {
            if (maybe > R2) {
                dbg_var(cc);
                dbg_var(bb);
                dbg_var(maybe);
                dbg_var(sum+i);
                assert(0);
            }
            
            total++;
        }
        generate(max_len, cifra+1, sum+i, cc);
    }
    cc[cifra] = 0;
    generate(max_len, cifra+1, sum, cc);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); // Remove in online problems!
    pot10[0] = 1;
    for (int i = 1; i <= 18; i++) pot10[i] = pot10[i-1] * 10ll;
    // vector<LL> bb = {1, 3, 2, 1, 2};
    // vector<int> seq = {0, 2, 3, 0, 0, 0, 0, 0, 0, 0};
    // cout << biggest(bb, 4, seq, 5) << endl;

    cin >> L >> R;
    
    R2 = R;
    while (R > 0) {
        bb.push_back(R % 10ll);
        R /= 10ll;
    }
    vector<int> cc(10, 0);
    generate(bb.size(), 1, 0, cc);
    cout << total << "\n";
}