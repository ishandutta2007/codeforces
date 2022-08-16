#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename S, typename T>
void xmin(S&a, T const&b){if(b<a) a=b;}
template<typename S, typename T>
void xmax(S&a, T const&b){if(b>a) a=b;}
const ll inf = 1e18;

template<class Segtree_Data>
struct Segtree{
    int N, height;
    vector<typename Segtree_Data::node_t> data;

    Segtree(int n):N(n), height(__builtin_clz(1)-__builtin_clz(N)), data(2*N, Segtree_Data::node_ne()){
        for(int i=N-1;i>=0;--i)
            data[i]=Segtree_Data::merge_nodes(data[i<<1], data[i<<1|1]);
    }
    void localUpdate(int pos, typename Segtree_Data::update_t const&val){
        Segtree_Data::update_node(data[pos], val);
    }
    void rePath(int pos){
        while(pos>>=1) data[pos] = Segtree_Data::merge_nodes(data[pos<<1], data[pos<<1|1]);
    }
    void update(int l, typename Segtree_Data::update_t const&val){
        l+=N;
        localUpdate(l, val);
        rePath(l);
    }
    typename Segtree_Data::node_t query(int l, int r){
        typename Segtree_Data::node_t retL=Segtree_Data::node_ne(), retR=Segtree_Data::node_ne();
        for(l+=N, r+=N;l<r;l>>=1, r>>=1){
            if(l&1)retL=Segtree_Data::merge_nodes(retL, data[l++]);
            if(r&1)retR=Segtree_Data::merge_nodes(data[--r], retR);
        }
        return Segtree_Data::merge_nodes(retL, retR);
    }
};
struct Segtreedata{
    // sum , msuff
    typedef pair<ll, ll> node_t;
    typedef ll update_t;
    static constexpr node_t node_ne() {return make_pair(0ll, 0ll);}
    static node_t merge_nodes(node_t const&left, node_t const&right){
        return node_t(left.first+right.first, max(left.second,right.second + left.first));
    }
    static void update_node(node_t &node, update_t const&update){
         node = make_pair(update, update);
    }
};

const int magic = 1;


signed main()
{
    #ifdef LOCAL_RUN
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    int TTT; cin >> TTT; while(TTT--){
    #else
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
    #endif // LOCAL_RUN

    int n;
    cin >> n;
    Segtree<Segtreedata> st(n);
    vector<int> a(n);
    array<vector<int>, 3> ocs;
    for(auto &e:a) cin >> e;
    //reverse(a.begin(), a.end());
    for(int i=0;i<n;++i){
        auto &e = a[i];
        ocs[e/1000].push_back(i);
    }
    array<int, 3> cur;
    cur[1] = 0;
    cur[2] = (int)ocs[2].size();
    ll ret = inf;
    ll addcost = 0;
    for(int i=0;i<n;++i){
        if(a[i] == 1000){
            st.update(i, 1000);
        } else {
            st.update(i, -200);
            addcost+=2000;
        }
    }
    for(int &i=cur[1];i<=(int)ocs[1].size();++i){
        for(int iter = 0;iter<magic && cur[2] < (int)ocs[2].size();++iter){
            st.update(ocs[2][cur[2]], -200);
            addcost+=2000;
            ++cur[2];
        }
        ll curcost = st.query(0, n).second + addcost;
        //cerr << cur[1] << " / " << cur[2] << " : " << curcost << "\n";
        while(cur[2]){
            --cur[2];
            st.update(ocs[2][cur[2]], 2000);
            addcost-=2000;
            ll newcost = st.query(0, n).second + addcost;
            //cerr << cur[1] << " / " << cur[2] << " : " << newcost << "\n";
            if(newcost > curcost){
                break;
            }
            xmin(curcost, newcost);
        }
        //cerr << cur[1] << " ->" << cur[2] << " : " << curcost << "\n";
        xmin(ret, curcost);
        if(i == (int)ocs[1].size()) break;
        st.update(ocs[1][i], -100);
        addcost+=1000;
    }
    cout << ret << "\n";


    #ifdef LOCAL_RUN
    }
    #endif // LOCAL_RUN
    return 0;
}