#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

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

struct node {
    node() {
        go[0] = NULL;
        go[1] = NULL;
        mark = 0;
    }
    
    node* go[2];
    int mark;
};

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n = input<int>();
    vector<pair<uint32_t, int>> lst_black, lst_white;

    for (int i = 0; i != n; ++i) {
        bool black = (input<char>() == '-');

        uint32_t msk = input<uint32_t>();
        input<char>();
        msk = msk << 8;
        
        msk |= input<uint32_t>();
        input<char>();
        msk = msk << 8;

        msk |= input<uint32_t>();
        input<char>();

        msk = msk << 8;

        msk |= input<uint32_t>();

        int kukarek = 32;
        if (cin.get() == '/')
            kukarek = input<int>();
        
        if (black)
            lst_black.emplace_back(msk, kukarek);
        else
            lst_white.emplace_back(msk, kukarek);
    }

    
    node* root = new node();

    for (auto elem: lst_white) {
        node* cur = root;
        cur->mark = 1;

        for (int i = 0; i < elem.second; ++i) {
            int bit = ((elem.first & (uint32_t(1) << uint32_t(31 - i))) != 0);

            if (cur->go[bit] == NULL)
                cur->go[bit] = new node();

            cur = cur->go[bit];
            cur->mark = 1;
        }

        cur->mark = 100;
    }

    auto fail = [&]() {
        cout << "-1\n";
        exit(0);
    };
    
    vector<pair<uint32_t, int>> ans;
    for (auto elem: lst_black) {
        node* cur = root;

        if (cur->mark == 100)
            fail();
        
        if (cur->mark == 2)
            continue;

        if (cur->mark == 0) {
            cur->mark = 2;
            ans.emplace_back(0, 0);
            continue;
        }

        uint32_t mask = 0;
        for (int i = 0; i < elem.second; ++i) {
            uint32_t bit = ((elem.first & (uint32_t(1) << uint32_t(31 - i))) != 0);

            mask |= (bit << uint32_t(31 - i));
            
            if (cur->go[bit] == NULL)
                cur->go[bit] = new node();

            cur = cur->go[bit];

            if (cur->mark == 100)
                fail();
            
            if (cur->mark == 2)
                break;

            if (cur->mark == 0) {
                cur->mark = 2;
                ans.emplace_back(mask, i + 1);
                break;
            }
        }

        if (cur->mark != 2)
            fail();
    }

    cout << SZ(ans) << "\n";
    for (auto elem: ans) {
        cout << ((elem.first >> uint32_t(24)) & uint32_t(255));
        cout << ".";
        cout << ((elem.first >> uint32_t(16)) & uint32_t(255));
        cout << ".";
        cout << ((elem.first >> uint32_t(8)) & uint32_t(255));
        cout << ".";
        cout << (elem.first & uint32_t(255));
        cout << "/" << elem.second << "\n";
    }
    
    return 0;
}