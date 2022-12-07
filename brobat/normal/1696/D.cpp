#include <bits/stdc++.h>
using namespace std;
#define int long long

template <typename T>
class SegTree {
public:
    vector <T> mx, mn;

    SegTree(int size) {
        // tree.resize(size);
        mn.resize(size);
        mx.resize(size);
    }

    void build(int node, int start, int end, vector <T> &v) {
        if(start == end) {
            mn[node] = v[start];
            mx[node] = v[start];
        } else {
            int mid = (start + end)/2;
            build(2*node, start, mid, v);
            build(2*node + 1, mid + 1, end, v);
            // tree[node] = func(tree[node*2], tree[node*2 + 1]);
            mn[node] = min(mn[node*2], mn[node*2 + 1]);
            mx[node] = max(mx[node*2], mx[node*2 + 1]);
        }
    }

    T query_min(int node, int start, int end, int l, int r) {
        if(l > r) {
            return (int)1E18; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return mn[node];
        }
        int mid = (start + end)/2;
        return min(query_min(node*2, start, mid, l, min(mid, r)), query_min(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }

    T query_max(int node, int start, int end, int l, int r) {
        if(l > r) {
            return 0; // Return appropriate value, for example INF for minimum.
        }
        if(l == start && r == end) {
            return mx[node];
        }
        int mid = (start + end)/2;
        return max(query_max(node*2, start, mid, l, min(mid, r)), query_max(node*2 + 1, mid + 1, end, max(l, mid + 1), r));
    }
};

// From - https://www.codingninjas.com/codestudio/library/next-greater-and-smaller-element-for-every-element-in-an-array 
vector<int> findNextGreaterElements(vector<int>&arr)
{
         
         int n=arr.size();
         vector<int>answer(n,-1);   //creates the answer array
      
         stack<int> s;   //creating an empty stack
         for (int i = 0; i < n; i++)   //traversing through the elements in the array
         {
             while (!s.empty() && arr[s.top()] < arr[i])   //finds next greater element
             {
                 answer[s.top()] = arr[i];
                 s.pop();
             }
             s.push(i);
         }
          return answer;
}
    
//Method to find the next smaller element for every array element
vector<int> findNextSmallerElements(vector<int>&arr)
{
         int n=arr.size();
         vector<int>answer(n,-1);   //creates the final array
         
         stack<int> s;   //creating an empty stack
         for (int i = 0; i < n; i++)   //traversing through the elements in the array
         {
             while (!s.empty() && arr[s.top()] > arr[i])   //finds next smaller element
             {
                 answer[s.top()] = arr[i];
                 s.pop();
             }
             s.push(i);
         }
          return answer;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector <int> v(n);
        map <int, int> pos;
        pos[-1] = -1;
        for(int i = 0; i < n; i++) {
            cin >> v[i];
            pos[v[i]] = i;
        }
        SegTree <int> st(4*n);
        st.build(1, 0, n - 1, v);
        vector<int> nge = findNextGreaterElements(v);
        vector<int> nle = findNextSmallerElements(v);
        vector <int> dp(n, (int)1E18);
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; i--) {
            dp[i] = dp[i + 1] + 1;
            int x, y;
            // assume v[i] is largest.
            x = pos[nge[i]];
            if(x == -1) x = n;
            y = st.query_min(1, 0, n - 1, i, x - 1);
            y = pos[y];
            dp[i] = min(dp[i], dp[y] + 1);
            // assume v[i] is smallest.
            x = pos[nle[i]];
            if(x == -1) x = n;
            y = st.query_max(1, 0, n - 1, i, x - 1);
            y = pos[y];
            dp[i] = min(dp[i], dp[y] + 1);
        }
        cout << dp[0] << '\n';
        // for(auto i : dp) cout << i << " ";
        // cout << '\n';
    }
    
    return 0;
}