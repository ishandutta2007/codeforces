// Dmitry _kun_ Sayutin (2020)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;

using std::cin;
using std::cout;
using std::cerr;

using std::vector;
using std::map;
using std::array;
using std::set;
using std::string;
using std::queue;

using std::pair;
using std::make_pair;

using std::tuple;
using std::make_tuple;
using std::get;

using std::min;
using std::abs;
using std::max;
using std::swap;

using std::unique;
using std::sort;
using std::generate;
using std::reverse;
using std::min_element;
using std::max_element;

#ifdef LOCAL
#define LASSERT(X) assert(X)
#else
#define LASSERT(X) {}
#endif

template <typename T>
T input() {
    T res;
    cin >> res;
    LASSERT(cin);
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()

const int mod = 998244353;

template <const int max_size, class HashType, class Data,
					const Data default_value>
struct hashTable {
	HashType hash[max_size];
	Data f[max_size];
	int size;

	int position(HashType H) const {
		int i = H % max_size;
		while (hash[i] && hash[i] != H)
			if (++i == max_size)
				i = 0;
		return i;
	}

	Data &operator[](HashType H) {
		assert(H != 0);
		int i = position(H);
		if (!hash[i]) {
			hash[i] = H;
			f[i] = default_value;
			size++;
		}
		return f[i];
	}
};

hashTable<1500 * 1500 * 3, uint64_t, int, 0> counts;

int main() {
    std::iostream::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // code here
    int n = input<int>();
    vector<vector<int>> mat(n, vector<int>(n));

    void* ptr = new string("go fuck yourself with hacks!");
    std::mt19937_64 rnd((size_t)(ptr));
    
    vector<uint64_t> vals(n);
    for (int i = 0; i < n; ++i) {
        vals[i] = rnd();
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cin >> mat[i][j];
    }

    //gp_hash_table<uint64_t, int> counts;
    int sets_sz = 0;

    map<uint64_t, int> id;
    
    for (int i = 0; i < n; ++i) {
        vector<int> order;
        order.reserve(n);

        for (int j = 0; j < n; ++j)
            if (i != j)
                order.push_back(j);

        sort(ALL(order), [&](int j1, int j2) {return mat[i][j1] < mat[i][j2];});

        order.insert(order.begin(), i);

        uint64_t curhash = 0;
        int curset_sz = 0;
        for (int elem: order) {
            curhash ^= vals[elem];
            curset_sz += 1;

            if ((++counts[curhash]) == curset_sz) {
                id[curhash] = sets_sz++;
            }
        }
    }

    vector<int> parent(sets_sz, -1);

    for (int i = 0; i < n; ++i) {
        vector<int> order;
        order.reserve(n);

        for (int j = 0; j < n; ++j)
            if (i != j)
                order.push_back(j);

        sort(ALL(order), [&](int j1, int j2) {return mat[i][j1] < mat[i][j2];});

        order.insert(order.begin(), i);

        vector<int> path;
        
        uint64_t curhash = 0;
        int curset_sz = 0;
        for (int elem: order) {
            curhash ^= vals[elem];
            curset_sz++;

            if (counts[curhash] == curset_sz) {
                path.push_back(id[curhash]);
            }
        }

        for (int p = 0; p + 1 < SZ(path); ++p)
            parent[path[p]] = path[p + 1];
    }

    int root = -1;
    vector<vector<int>> gr(sets_sz);
    for (int i = 0; i < sets_sz; ++i)
        if (parent[i] == -1)
            root = i;
        else
            gr[parent[i]].push_back(i);

    std::function<vector<int>(int)> calc_dp = [&](int v) {
        if (gr[v].empty())
            return vector<int> {0, 1};
        
        vector<int> self = {1};

        for (int u: gr[v]) {
            auto rs = calc_dp(u);

            vector<int> newself(SZ(self) + SZ(rs) - 1);

            for (int i = 0; i < SZ(self); ++i)
                for (int j = 0; j < SZ(rs); ++j)
                    newself[i + j] = (newself[i + j] + self[i] * (int64_t)rs[j]) % mod;

            self = std::move(newself);
        }

        self.resize(max(SZ(self), 2));
        self[1] += 1;
        if (self[1] == mod)
            self[1] = 0;

        return self;
    };

    auto rs = calc_dp(root);
    for (int i = 1; i <= n; ++i)
        cout << rs[i] << " ";
    cout << "\n";
    
    return 0;
}