// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize("unroll-loops")

#include <stdio.h>
#include <bits/stdc++.h>

#ifdef PERVEEVM_LOCAL
    #define debug(x) std::cerr << (#x) << ":\t" << (x) << std::endl
#else
    #define debug(x) 238;
#endif

#define fastIO std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0)
#define NAME "File"

using ll = long long;
using ld = long double;

#ifdef PERVEEVM_LOCAL
    std::mt19937 rnd(238);
#else
    std::mt19937 rnd(std::chrono::high_resolution_clock::now().time_since_epoch().count());
#endif

template<typename T>
bool smin(T& a, const T& b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<typename T>
bool smax(T& a, const T& b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const double PI = atan2(0.0, -1.0);
const int INF = 0x3f3f3f3f;
const ll LINF = (ll)2e18;

std::string trim(const std::string& s) {
    std::string res;
    bool open = false;
    for (auto c : s) {
        if (c == '\"') {
            open ^= true;
        }

        if (c == ' ' && !open) {
            continue;
        }
        res.push_back(c);
    }
    return res;
}

void run() {
    fastIO;

    std::string buffer;
    std::getline(std::cin, buffer);

    std::vector<std::tuple<int, std::string, std::string>> shit;
    while (std::getline(std::cin, buffer)) {
        buffer = trim(buffer);
        if (buffer.empty()) {
            continue;
        }

        if (buffer[0] == 't' && buffer[1] == 'r') {
            shit.push_back(std::make_tuple(1, "", ""));
        } else if (buffer[0] == 't' && buffer[1] == 'h') {
            int pos1 = buffer.find('(');
            int pos2 = buffer.find(')');
            std::string type = buffer.substr(pos1 + 1, pos2 - pos1 - 1);
            shit.push_back(std::make_tuple(2, type, ""));
        } else if (buffer[0] == 'c') {
            int pos1 = buffer.find('(');
            int pos2 = buffer.find(',');
            std::string type = buffer.substr(pos1 + 1, pos2 - pos1 - 1);
            pos1 = buffer.find('\"');
            pos2 = buffer.rfind('\"');
            std::string msg = buffer.substr(pos1 + 1, pos2 - pos1 - 1);
            shit.push_back(std::make_tuple(3, type, msg));
        } else {
            throw;
        }
    }    

    std::vector<int> st;
    for (int i = 0; i < (int)shit.size(); ++i) {
        auto[lineType, type, msg] = shit[i];
        if (lineType == 1) {
            st.push_back(i);
        } else if (lineType == 2) {
            continue;
        } else {
            shit[st.back()] = std::make_tuple(1, type, msg);
            st.pop_back();
        }
    }

    // for (auto[lineType, type, msg] : shit) {
    //     std::cout << lineType << ' ' << type << ' ' << msg << std::endl;
    // }

    st.clear();
    for (int i = 0; i < (int)shit.size(); ++i) {
        auto[lineType, type, msg] = shit[i];
        if (lineType == 1) {
            st.push_back(i);
        } else if (lineType == 2) {
            while (!st.empty()) {
                int id = st.back();
                st.pop_back();

                auto[prevLineType, prevType, prevMsg] = shit[id];
                // debug(id);
                // debug(type);
                // debug(prevType);
                if (prevType == type) {
                    std::cout << prevMsg << '\n';
                    return;
                }
            }

            std::cout << "Unhandled Exception\n";
            return;
        } else {
            st.pop_back();
        }
    }
}

int main(void) {
    // freopen(NAME".in", "r", stdin);
    // freopen(NAME".out", "w", stdout);

    auto start = std::chrono::high_resolution_clock::now();
    run();
    auto end = std::chrono::high_resolution_clock::now();

    #ifdef PERVEEVM_LOCAL
        std::cerr << "Execution time: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
                  << " ms" << std::endl;
    #endif

    return 0;
}