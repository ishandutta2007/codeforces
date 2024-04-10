#include<bits/stdc++.h>
using namespace std ;

#define ll              long long 
#define pb              push_back
#define all(v)          v.begin(),v.end()
#define sz(a)           (ll)a.size()
#define F               first
#define S               second
#define INF             2000000000000000000
#define popcount(x)     __builtin_popcountll(x)
#define pll             pair<ll,ll>
#define pii             pair<int,int>
#define ld              long double

const int M = 1000000007;
const int MM = 998244353;

template<typename T, typename U> static inline void amin(T &x, U y){ if(y<x) x=y; }
template<typename T, typename U> static inline void amax(T &x, U y){ if(x<y) x=y; }

#ifdef LOCAL
#define debug(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 2351
#endif

struct priority_queu {
    vector<int> heap;

    void down_heapify(int cur)
    {
        int l = cur * 2 + 1,r = 2 * cur + 2;
        int go = cur;
        if(l < heap.size() && heap[l] > heap[cur] && heap[l] > heap[go])
            go = l;

        if(r < heap.size() && heap[r] > heap[cur] && heap[r] > heap[go])
            go = r;

        if(go != cur)
            swap(heap[cur],heap[go]),down_heapify(go);
    }

    void push(int x)
    {
        int id = heap.size();
        heap.push_back(x);
        // up heapify
        while(id && heap[id] > heap[(id-1)/2])
        {
            swap(heap[id],heap[(id-1)/2]);
            id = (id - 1)/2;
        }
    }

    int top()
    {
        if(heap.empty())
        {
            cout << "Seg Fault :)";
            exit(0);
        }
        return heap[0];
    }

    void pop()
    {
        if(heap.empty())
        {
            cout << "Seg Fault :)";
            exit(0);
        }
        heap[0] = heap.back();
        heap.pop_back();
        down_heapify(0);
    }

    bool empty()
    {
        return heap.empty();
    }
};


int _runtimeTerror_()
{
    int n;
    cin>>n;
    vector<pii> a;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        a.push_back({x+y,x-y});
    }
    sort(a.begin(),a.end());
    // debug(a);
    priority_queue<int,vector<int>,greater<int>> R;
    priority_queu L;
    L.push(0);
    R.push(0);
    int64_t ans = 0;
    int pr = 0;
    int l_sh = 0,r_sh = 0;
    for(auto &[x,y]:a)
    {
        int d = abs(x - pr);
        pr = x;
        l_sh -= d, r_sh += d;
        // debug(L.top()+l_sh,R.top()+r_sh,y);
        if(y >= L.top() + l_sh && y <= R.top() + r_sh)
        {
            L.push(y-l_sh);
            R.push(y-r_sh);
        }
        else if(y > R.top() + r_sh)
        {
            ans += abs(y-R.top()-r_sh);
            R.push(y-r_sh);
            R.push(y-r_sh);
            L.push(R.top()+r_sh-l_sh);
            R.pop();
        }
        else
        {
            ans += abs(y - L.top()-l_sh);
            L.push(y-l_sh);
            L.push(y-l_sh);
            R.push(L.top()+l_sh-r_sh);
            L.pop();
        }
    }
    ans /= 2;
    cout << ans << "\n";
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    #ifdef runSieve
        sieve();
    #endif
    #ifdef NCR
        initialize();
    #endif
    int TESTS=1;
    //cin>>TESTS;
    while(TESTS--)
        _runtimeTerror_();
    return 0;
}