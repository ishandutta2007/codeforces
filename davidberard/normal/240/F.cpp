#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pii;

#ifdef LOCAL
#define prepare
#else
#define prepare freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif

struct node {
    int cnt[26], dir;
    node() {
        memset(cnt, 0, sizeof cnt);
        dir = 1;
    }
    int &operator[] (const int& i) { return cnt[i]; }
    node &operator += (const node& o) {
        for (int i=0; i<26; ++i) cnt[i] += o.cnt[i];
        return *this;
    }
    node &operator= (const node& o) {
        memcpy(cnt, o.cnt, sizeof(int)*26);
        dir = o.dir;
        return *this;
    }
    bool empty() const {
        for (int i=0; i<26; ++i) if (cnt[i]) return false;
        return true;
    }
    size_t size() const {
        size_t ans = 0;
        for (int i=0; i<26; ++i) ans += cnt[i];
        return ans;
    }
    string to_str() const {
        string ans;
        for (int j=0; j<26; ++j) {
            for (int k=0; k<cnt[j]; ++k) ans += (char)(j+'a');
        }
        return ans;
    }
    node split(int jump, int len) const {
        //cerr << "  SPL " << jump << " " << len << " ON " << to_str() << endl;
        node ans;
        if (dir == 1) {
            int sum = 0;
            int i=0;
            for (; i<26 && sum+cnt[i]<=jump; ++i) {
                sum += cnt[i];
            }
            assert(i<26);
            ans[i] = min(sum+cnt[i]-jump, len);
            sum = ans[i];
            for (++i; i<26 && sum+cnt[i]<=len; ++i) {
                sum += cnt[i];
                ans[i] = cnt[i];
            }
            if (sum < len) {
                assert (i<26);
                //cerr << "! " << sum+cnt[i]-len << " " << len-sum << " : " << sum << " " << cnt[i] << " " << len << endl;
                ans[i] = min(cnt[i], len-sum);
            }
        } else {
            int sum = 0;
            int i=25;
            for (; i>=0 && sum+cnt[i]<=jump; --i) {
                sum += cnt[i];
            }
            assert (i>=0);
            ans[i] = min(sum+cnt[i]-jump, len);
            sum = ans[i];
            for (--i; i>=0 && sum+cnt[i]<=len; --i) {
                sum += cnt[i];
                ans[i] = cnt[i];
            }
            if (sum < len) {
                assert (i>=0);
                ans[i] = min(cnt[i], len-sum);
            }
        }


        //cerr << " split '" << to_str() << "' with " << jump << " " << len << " on " << dir << " gives '" << ans.to_str() << "'" << endl;

        ans.dir = dir;
        assert(ans.size() == len);

        return ans;
    }
    bool is_palindrome() const {
        int seen = 0;
        for (int i=0; i<26; ++i) {
            if (cnt[i]%2 && seen++) return false;
        }
        return true;
    }
    int get() const {
        for (int i=0; i<26; ++i) if(cnt[i]) return i;
        assert(false);
    }

};

struct segtree {
    vector<node> t;
    vector<node> d;
    int n, h;
    segtree(string s) {
        int sz = s.size();
        h = 32 - __builtin_clz(sz);
        n = 1<<h;
        t = vector<node>(n<<1);
        d = vector<node>(n<<1);
        for (int i=0; i<sz; ++i) {
            t[i+n][s[i]-'a']++;
        }
        for (int i=n-1; i; --i) {
            t[i] = t[i<<1];
            t[i] += t[i<<1|1];
        }
    }
    void apply(int x, const node& v) {
        t[x] = v;
        d[x] = v;
    }

    void pushh(int x, int sz) {
        if (!d[x].empty()) {
            apply(x<<1, d[x].split(0, sz/2));
            apply(x<<1|1, d[x].split(sz/2, sz/2));
            d[x] = node();
        }
    }

    void push(int x) {
        for (int i=h, sz=n; i; --i, sz/=2) {
            pushh(x>>i, sz);
        }
    }

    void pulll(int x) {
        assert (d[x].empty());
        t[x] = t[x<<1];
        t[x] += t[x<<1|1];
    }

    void apply(int l, int r, const node &v, int x=1, int lv=0, int rv=-1) {
        if (rv == -1) rv = n;
        if (r<=lv||rv<=l) return;
        if (l<=lv && rv<=r) {
            apply(x, v.split(lv-l, rv-lv));
            return;
        }
        int m = (lv+rv)/2;
        pushh(x, rv-lv);
        apply(l, r, v, x*2, lv, m);
        apply(l, r, v, x*2+1, m, rv);
        pulll(x);
    }
    node query(int l, int r) {
        node ans;
        push(l+n);
        push(r+n-1);
        for (l+=n, r+=n; l<r; l/=2, r/=2) {
            if (l%2) {
                ans += t[l++];
            }
            if (r%2) {
                ans += t[--r];
            }
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    prepare;

    int n, m;
    cin >> n >> m;
    string s_init;
    cin >> s_init;
    segtree st(s_init);

    while (m--) {
        int x, y;
        cin >> x >> y;
        node v = st.query(x-1, y);
        if (!v.is_palindrome()) continue;

        //cerr << " V is " << v.to_str() << endl;

        node update;
        bool odd = false;
        int special = -1;
        for (int i=0; i<26; ++i) {
            if (v[i]%2) {
                //cerr << "  SPECIAL" << i << endl;
                assert (!odd);
                update[i] = v[i]/2;
                odd = true;
                special = i;
                continue;
            }
            update[i] = v[i]/2;
        }

        if (odd) assert((y-x+1)%2 == 1);

        update.dir = 1;
        st.apply(x-1, (x+y-1)/2, update);
        update.dir = -1;
        st.apply((x+y)/2, y, update);
        if (odd) {
            node tu;
            tu[special]++;
            st.apply((x+y-1)/2, (x+y-1)/2+1, tu);
        }
    }

    //cerr << "~~" << endl;

    for (int i=1, sz=st.n; i<st.n; ++i) {
        st.pushh(i, sz);
        if (__builtin_popcount(i) + __builtin_clz(i) == 32) sz /= 2;
    }

    for (int i=0; i<n; ++i) {
        cout << (char) (st.t[i+st.n].get()+'a');
    }
    cout << "\n";

    return 0;
}