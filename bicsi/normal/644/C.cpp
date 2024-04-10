#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int64_t> Map;
unordered_set<int64_t> Viz;
unordered_map<int64_t, vector<string>> Hosts;

int64_t has(char *x) {
    int64_t h = 0;
    while(*x) {
        h *= 321091;
        h += *x;
        x++;
    }
    return h;
}

int64_t lgpow(int64_t e) {
    int64_t r = 1, b = 391287;
    while(e) {
        if(e % 2) r *= b;
        b *= b;
        e /= 2;
    }
    return r;
}

void addHash(char *x, char *y) {
//    cerr << x << " " << y << '\n';
    auto &t = Map[string(x)];
    t += lgpow(has(y));
}

char hn[50];

int main() {
//    freopen("input", "r", stdin);
    int n;
    scanf("%d", &n);

    while(n--) {
        scanf("%s", hn);
        char *hostname = hn + 7;

        if(Viz.count(has(hostname))) continue;
        Viz.insert(has(hostname));

        char *p = hostname;
        while(*p && *p != '/') p++;

        if(*p == 0) {
            addHash(hostname, "_212EMPTY310");
        } else {
            *p = 0;
            addHash(hostname, p + 1);
        }
    }

    for(auto p : Map) {
        Hosts[p.second].push_back(p.first);
    }

    int cnt = 0;

    for(auto p : Hosts) {
        if(p.second.size() > 1) {
            cnt += 1;
        }
    }

    cout << cnt << '\n';

    for(auto p : Hosts) {
        if(p.second.size() > 1) {
            for(string x : p.second)
                cout << "http://" << x << " ";
            cout << '\n';
        }
    }
    return 0;
}