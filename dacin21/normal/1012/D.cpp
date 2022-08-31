#undef _GLiBCXX_DEBUG

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}

int count_flips(string const&s){
    int ret = 0;
    for(int i=1;i<(int)s.size();++i){
        if(s[i] != s[i-1]){
            ++ret;
        }
    }
    return ret;
}

int kth_flip(string const&s, int k){
    if(k == 0){
        return 0;
    }
    --k;
    for(int i=1;i<(int)s.size();++i){
        if(s[i] != s[i-1]){
            if(k == 0){
                return i;
            }
            --k;
        }
    }
    if(k == 0){
        return (int)s.size()-1;
    }
    assert(0);
    return -1;
}

vector<pair<int, int> > finish(string s, string t){
    vector<pair<int, int> > ret;
    char const x = s.back(), y = t.back();
    assert(x!=y);
    for(;!s.empty() || !t.empty();){
        while(!s.empty() && s.back() == x) s.pop_back();
        while(!t.empty() && t.back() == y) t.pop_back();
        ret.emplace_back(s.size(), t.size());
        s.swap(t);
    }
    ret.pop_back();
    return ret;
}

vector<pair<int, int> > solve(string const&s, string const&t){
    int x = count_flips(s), y = count_flips(t);
    if(x > y){
        auto tmp = solve(t, s);
        for(auto &e:tmp) swap(e.first, e.second);
        return tmp;
    }
    assert(x<=y);
    vector<pair<int, int> > ret(s.size()+t.size()+10, make_pair(-1, -1));
    auto cand = [&](int a, int b){
        assert(0<=a && a<(int)s.size());
        assert(0<=b && b<(int)t.size());
        auto tmp = finish(t.substr(0, b) + s.substr(a), s.substr(0, a) + t.substr(b));
        if(a!=0 || b!=0){
            tmp.insert(tmp.begin(), make_pair(a, b));
        }
        if(tmp.size() < ret.size()){
            ret=move(tmp);
        }
    };
    for(int i=0;i<=min(4, x+1);++i){
        const int A = kth_flip(s, i);
        const int m = (y-x+2*i)/2;
        for(int j = max(0, m-4);j<=min(y+1, m+4);++j){
            const int B = kth_flip(t, j);
            cand(A, B);
        }
    }
    return ret;
}
signed brute(string const&s, string const&t){
    set<pair<string, string> > vis;
    queue<pair<string, string> > q;
    auto enqueue = [&](string const&s, string const&t){
        auto key = make_pair(s, t);
        if(vis.count(key)) return;
        vis.insert(key);
        q.push(key);
    };
    enqueue(s, t);
    q.emplace(string(""),string(""));
    int ret = 0;
    while(q.size() > 1){
        auto tmp = q.front();
        q.pop();
        if(tmp.first == "" && tmp.second == ""){
            q.emplace(tmp);
            ++ret;
        } else {
            if(tmp.first.find('a') == -1 && tmp.second.find('b') == -1){
                return ret;
            }
            if(tmp.first.find('b') == -1 && tmp.second.find('a') == -1){
                return ret;
            }
            for(int i=0;i<=(int)tmp.first.size();++i){
                for(int j=0;j<=(int)tmp.second.size();++j){
                    enqueue(
                            tmp.second.substr(0, j)+tmp.first.substr(i),
                            tmp.first.substr(0, i)+tmp.second.substr(j)
                            );
                }
            }
        }
    }
    assert(0);
    return ret;
}

signed gen(int t){
    const int n = 100;
    mt19937 rng(5325);
    auto get_rand = [&](int a, int b){return uniform_int_distribution<int>(a, b)(rng);};
    auto get_string = [&](){
        int x = get_rand(1, n);
        string ret;
        for(int i=0;i<x;++i){
            ret+=(char)('a' + get_rand(0, 1));
        }
        return ret;
    };
    ofstream o("gen.txt");
    o << t << "\n";
    while(t--){
        o << get_string() << "\n" << get_string() << "\n";
    }
    o << endl;
    o.close();
    return 0;
}

void check(string s, string t, vector<pair<int, int> > const&v){
    auto d = [&](int i, int j){
        assert(0<=i && i<=s.size());
        assert(0<=j && j<=t.size());
        string a = s.substr(0, i) + t.substr(j);
        string b = t.substr(0, j) + s.substr(i);
        t = a;
        s = b;
    };
    for(auto const&e:v){
        d(e.first, e.second);
    }
    if(s.find('a') == -1 && t.find('b') == -1) return;
    if(s.find('b') == -1 && t.find('a') == -1) return;
    assert(0);

}

signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT;
    if(TTT<0) return gen(-TTT);
    while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    string s, t;
    cin >> s >> t;

    //const int bans = brute(s, t);

    s+="a";
    t+="b";
    auto ans_1 = solve(s, t);
    swap(s.back(), t.back());
    auto ans_2 = solve(s, t);
    if(ans_1.size() > ans_2.size()){
        ans_1.swap(ans_2);
        swap(s.back(), t.back());
    }
    //if(s.size() + t.size() < 1000) check(s.substr(0, s.size()-1), t.substr(0, t.size()-1), ans_1);

    /*if((int)ans_1.size() != bans){
        cerr << "!!!" << s << " " << t << " " << ans_1.size() << " " << bans << "\n";;
    }*/

    cout << ans_1.size() << "\n";
    for(auto &e:ans_1){
        cout << e.first << " " << e.second << "\n";
    }

    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}