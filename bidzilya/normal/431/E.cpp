#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
  
typedef long long ll;

const int max_n = 1e5 + 1;

int n, q;
int a[max_n];

struct treap
{
    treap* left;
    treap* right;
    
    int prior;
    int key;
    
    ll sum;
    int cnt;
    
    treap(int _key) :
        left(NULL),
        right(NULL),
        prior(rand()),
        key(_key),
        sum(_key),
        cnt(1)
    {
    }
};

typedef treap* ptreap;

ptreap root;

inline int get_cnt(ptreap T)
{
    return (T == NULL ? 0 : T->cnt);
}

inline ll get_sum(ptreap T)
{
    return (T == NULL ? 0 : T->sum);
}

inline ptreap get_left(ptreap T)
{
    return (T == NULL ? NULL : T->left);
}

inline ptreap get_right(ptreap T)
{
    return (T == NULL ? NULL : T->right);
}

void update_values(ptreap& T)
{
    if (T != NULL) {
        T->sum = T->key + get_sum(T->left) + get_sum(T->right);
        T->cnt = 1 + get_cnt(T->left) + get_cnt(T->right);
    }
}

void split(ptreap T, ptreap& L, ptreap& R, int key)
{
    if (T == NULL) {
        L = R = NULL;
    } else {
        if (T->key <= key) {
            L = T;
            split(T->right, L->right, R, key);
            update_values(L);
        } else {
            R = T;
            split(T->left, L, R->left, key);
            update_values(R);
        }
    }
}

ptreap merge(ptreap L, ptreap R)
{
    if (L == NULL)
        return R;
    if (R == NULL)
        return L;
    if (L->prior >= R->prior) {
        L->right = merge(L->right, R);
        update_values(L);
        return L;
    } else {
        R->left = merge(L, R->left);
        update_values(R);
        return R;
    }
}

void tadd(ptreap& T, int key)
{
    ptreap L, R;
    split(T, L, R, key);
    ptreap M = new treap(key);
    T = merge(L, merge(M, R));
}

void tdel(ptreap& T, int key)
{
    ptreap L, M, R;
    split(T, L, R, key);
    split(L, L, M, key - 1);
    M = merge(get_left(M), get_right(M));
    T = merge(L, merge(M, R));
}

int get_kth(ptreap T, int k)
{
    if (get_cnt(T->left) >= k) 
        return get_kth(T->left, k);
    if (get_cnt(T->left) + 1 == k) {
        return T->key;
    }
    return get_kth(T->right, k - (get_cnt(T->left) + 1));
}

ll get_sum_kth(ptreap T, int k)
{
    if (get_cnt(T->left) >= k) {
        return get_sum_kth(T->left, k);
    }
    ll res = get_sum(T->left) + T->key;
    if (k > 1 + get_cnt(T->left)) {
        res += get_sum_kth(T->right, k - (get_cnt(T->left) + 1));
    }
    return res;
}

bool check_condition(ll sum, int cnt, int val, ll v)
{
    return 1LL * val * cnt - sum <= v;
}

double get_ans(ll v)
{
    int lo = 1;
    int hi = n;
    int k = 1;
    while (lo <= hi) {
        int mi = (lo + hi) >> 1;
        
        if (check_condition(get_sum_kth(root, mi), mi, get_kth(root, mi), v)) {
            k = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    v += get_sum_kth(root, k);
    
    return 1.0 * v / k;
}

int main()
{
    srand(time(NULL));
    
    ios_base::sync_with_stdio(false);
    
  //  freopen("input.txt", "r", stdin);
  //  freopen("output.txt", "w", stdout);

    root = NULL;
    
    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        tadd(root, a[i]);
    }

    cout << fixed << setprecision(4);
    
    for (int i = 0; i < q; ++i) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            tdel(root, a[p]);
            a[p] = x;
            tadd(root, a[p]);
        } else {
            ll v;
            cin >> v;
            cout << get_ans(v) << '\n';
        }
    }

    cout.flush();

    return 0;
}