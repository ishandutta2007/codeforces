#include <bits/stdc++.h>
using namespace std;
using namespace std::placeholders;

#define llong long long 
#define xx first
#define yy second
#define len(x) ((int)x.size())
#define rep(i,n) for (int i = -1; ++ i < n; )
#define rep1(i,n) for (int i = 0; i ++ < n; )
#define all(x) x.begin(), x.end()
// #define rand __rand
// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());  // or mt19937_64
// template<class T = int> T rand(T range = numeric_limits<T>::max()) {
    // return (T)(rng() % range);
// }

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
map<char, int> dir {
    {'A', 0}, {'W', 1}, {'D', 2}, {'S', 3},
    {'a', 2}, {'w', 3}, {'d', 0}, {'s', 1},
};
struct offset_rect {
    int width, height;
    int offset_x, offset_y;

    offset_rect(int w = 1, int h = 1, int ofs_x = 0, int ofs_y = 0)
        : width(w), height(h), offset_x(ofs_x), offset_y(ofs_y) {}

    offset_rect advance(int dx_, int dy_) {
        offset_rect res = *this;
        res.offset_x += dx_;
        res.offset_y += dy_;
        if (res.offset_x < 0) {
            res.width -= res.offset_x;
            res.offset_x = 0;
        }
        if (res.offset_x >= width) {
            res.width = res.offset_x + 1;
        }

        if (res.offset_y < 0) {
            res.height -= res.offset_y;
            res.offset_y = 0;
        }
        if (res.offset_y >= height) {
            res.height = res.offset_y + 1;
        }
        return res;
    }

    offset_rect advance(char d) { 
        return advance(dx[dir[d]], dy[dir[d]]);
    }

    llong area() const {
        return 1ll * width * height;
    }
};

ostream& operator<<(ostream& cout, const offset_rect& r) {
    return cout << "(" << r.width << ", " << r.height << ") (" << r.offset_x << ", " << r.offset_y << ")";
}

bool operator< (const offset_rect& u, const offset_rect& v) {
    return u.area() < v.area();
}

offset_rect combine(const offset_rect& u, const offset_rect& v) {
    int max_x = max(u.offset_x, v.offset_x);
    int max_y = max(u.offset_y, v.offset_y);
    return offset_rect(
        max_x + max(u.width - u.offset_x, v.width - v.offset_x),
        max_y + max(u.height - u.offset_y, v.height - v.offset_y),
        max_x, max_y
    );
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int ntest; cin >> ntest;
    rep1(testcase, ntest) {
        string s; cin >> ws >> s;
        vector<offset_rect> from_left(len(s) + 1), from_right(len(s) + 1);
        rep(i, len(s)) {
            from_left[i + 1] = from_left[i].advance(s[i]);
        }

        // clog << s << endl;
        // for (auto i: from_left) clog << i << endl;

        for (int i = len(s); i--; ) from_right[i] = from_right[i + 1].advance((char)tolower(s[i]));

        offset_rect ans = from_left.back();
        rep(i, len(s) + 1) {
            rep(d, 4) {
                ans = min(ans, combine(from_right[i], from_left[i].advance(dx[d], dy[d])));
            }
        }
        cout << ans.area() << '\n';
    }

    return 0;
}