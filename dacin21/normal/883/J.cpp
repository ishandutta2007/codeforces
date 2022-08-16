#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}
template<class Segtree_Data>
struct Segment_Tree{
	using T = typename Segtree_Data::node_t;
	using S = typename Segtree_Data::update_t;
	int n;
	ll sum = 0;
	vector<T>data;
	Segment_Tree(int _n):n(_n), data(2*n, make_pair(0ll, 0ll)){
		for(int i=n-1;i>=0;--i) data[i] = Segtree_Data::merge_nodes(data[i<<1], data[i<<1|1]);
	}
	Segment_Tree(vector<T> const&base):n(base.size()), data(2*n, Segtree_Data::node_ne()){
		copy(base.begin(), base.end(), data.begin()+n);
		for(int i=n-1;i>=0;--i) data[i] = Segtree_Data::merge_nodes(data[i<<1], data[i<<1|1]);
	}
	void update(int pos, S const&val){
	    sum+=val;
		for(Segtree_Data::update_node(data[pos+=n], val);pos>>=1;){
			data[pos] = Segtree_Data::merge_nodes(data[pos<<1], data[pos<<1|1]);
		}
	}
	T query(int l, int r)const{
		T retL = Segtree_Data::node_ne(), retR = Segtree_Data::node_ne();
		for(l+=n, r+=n;l<r;l>>=1, r>>=1){
			if(l&1) retL = Segtree_Data::merge_nodes(retL, data[l++]);
			if(r&1) retR = Segtree_Data::merge_nodes(data[--r], retR);
		}
		return Segtree_Data::merge_nodes(retL, retR);
	}
};
struct Segtreedata{
    typedef pair<ll, ll> node_t;
    typedef ll update_t;
    static constexpr node_t node_ne() {return make_pair(0, 1e15);}
    static node_t merge_nodes(node_t const&left, node_t const&right){
        return node_t(left.first+right.first, min(left.second, right.second+left.first));
    }
    static void update_node(node_t &node, update_t const&update){
        node.first+=update;
        node.second+=update;
    }
};

int brute(int n, int m, vector<ll> const&a, vector<ll> const&b, vector<ll> const&p){
    int ret = 0;
    for(int k=0;k<(1<<m);++k){
        vector<ll> cost(n, 0);
        bool f = false;
        for(int i=0;i<m;++i){
            if(k&(1<<i)){
                bool ff = true;
                for(int j=n-1;j>=0;--j){
                    if(a[j]>=b[i]){
                        cost[j]+=p[i];
                        ff=false;
                        break;
                    }
                }
                if(ff){
                    f=true;
                    break;
                }
            }
        }
        ll cur = 0;
        for(int i=0;i<n;++i){
            cur+=a[i];
            cur-=cost[i];
            if(cur<0) f=true;
        }
        if(!f){
            int c = __builtin_popcount(k);
            if(c>ret){
                //cerr << bitset<16>(k) << "\n";
            }
            xmax(ret, c);
        }
    }
    return ret;

}

signed gen(int T){
    mt19937 rng(35236);
    ofstream o("gen.txt");
    auto getrand = [&](ll a, ll b){return uniform_int_distribution<ll>(a, b)(rng);};
    o << T << "\n";
    while(T--){
        int n = getrand(1, 10), m = getrand(1, 10);
        o << n << " " << m << "\n";
        for(int i=0;i<n;++i){
            o << getrand(1, 100) << " ";
        }
        o << "\n";
        for(int i=0;i<m;++i){
            o << getrand(1, 100) << " ";
        }
        o << "\n";
        for(int i=0;i<m;++i){
            o << getrand(1, 100) << " ";
        }
        o << "\n";
        o << "\n";
    }
    o << endl;
    return 0;

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

    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m), p(m);
    for(auto &e:a) cin >> e;
    for(auto &e:b) cin >> e;
    for(auto &e:p) cin >> e;
    Segment_Tree<Segtreedata> st(n+1);
    for(int i=0;i<n;++i){
        st.update(i+1, a[i]);
    }
    vector<pair<int, int> > adec;
    for(int i=0;i<n;++i){
        while(adec.size() && adec.back().first<=a[i]) adec.pop_back();
        adec.emplace_back(a[i], i+1);
    }
    reverse(adec.begin(), adec.end());
    auto deca =[&](int cost){
        auto it = lower_bound(adec.begin(), adec.end(), make_pair(cost, -1));
        if(it == adec.end()) return 0;
        return it->second;
    };

    int ret = 0;
    vector<int> id(m);
    iota(id.begin(), id.end(), 0);
    sort(id.begin(), id.end(), [&](int const&i, int const&j){return p[i]<p[j];});
    for(auto const&i:id){
        //cerr << "build #" << i << "\n";
        //cerr << b[i] << "/" << p[i] << " : ";
        int t = deca(b[i]);
        auto tmp =st.query(t, n+1);
        ll cash = tmp.second+st.sum - tmp.first;
        //cerr << t << "/" << cash << "\n";
        if(cash>=p[i]){
            st.update(t, -p[i]);
            ++ret;
        }
    }
    /*int bruteret = brute(n, m, a, b, p);
    if(ret!=bruteret){
        cerr << "!! " << ret << " / " << bruteret << "\n";
    }*/
    cout << ret << "\n";



    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}