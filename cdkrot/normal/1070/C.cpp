#include <bits/stdc++.h>

using namespace std;

#define se second
#define fi first
#define forn(i, n) for (int i = 0; i < n; i++)
#define sz(a) (int)a.size()
#define mp make_pair 

typedef long long ll;

ll my_rand()
{
    return (rand() << 16ll) + rand();
}

struct  Node
{
    ll c, p, y, sum, cnt;
    Node *l, *r;
    Node (ll c_ = 0, ll p_ = 0, ll y_ = my_rand(), Node* l_ = NULL, Node* r_ = NULL): c(c_), p(p_), y(y_), sum(c_ * p_), cnt(c_), l(l_), r(r_) {};
};

ll sum(Node* v)
{
    if (v == NULL)
        return 0;
    return v->sum;
}

ll cnt(Node* v)
{
    if (v == NULL)
        return 0;
    return v->cnt;
}

void update(Node* v)
{
    if (v == NULL)
        return;
    v->sum = sum(v->l) + sum(v->r) + v->c * v->p;
    v->cnt = cnt(v->l) + cnt(v->r) + v->c;
}

Node* merge(Node* v, Node* u)
{
    if (v == NULL)
        return u;
    if (u == NULL)
        return v;
    Node* ans;
    if (v->y < u->y)
    {
        v->r = merge(v->r, u);
        ans = v;
    }
    else
    {
        u->l = merge(v, u->l);
        ans = u;
    }
    update(ans);
    return ans;
}

pair<Node*, Node*> split(Node* v, ll x)
{
    if (v == NULL)
        return {v, v};
    pair<Node*, Node*> p;
    if (v->p < x)
    {
        p = split(v->r, x);
        v->r = p.first;
        p.first = v;
    }
    else
    {
        p = split(v->l, x);
        v->l = p.second;
        p.second = v;
    }
    update(v);
    return p;
}

Node* ins(Node* v, Node * u)
{
    if (v == NULL)
        return u;
    if (v->y < u->y)
    {
        auto p = split(v, u->p);
        u->l = p.first;
        u->r = p.second;
        update(u);
        return u;
    }
    if (u->p < v->p)
        v->l = ins(v->l, u);
    else
        v->r = ins(v->r, u);
    update(v);
    //cout << "?" << v->p << endl;
    return v;
}

Node* era(Node* v, ll p, ll c)
{
    if (v == NULL)
        return v;
    if (v->p == p)
    {
        if (v->c == c)
            return merge(v->l, v->r);
        else
        {
            v->c -= c;
            update(v);
            return v;
        }
    }
    if (p < v->p)
        v->l = era(v->l, p, c);
    else
        v->r = era(v->r, p, c);
    update(v);
    return v;
}

void add(Node*v, ll c, ll p)
{
    if (v == NULL)
        return;
    if (v->p == p)
        v->c += c;
    else if (v->p > p)
        add(v->l, c, p);
    else
        add(v->r, c, p);
    update(v);
}

bool find(Node* v, ll p)
{
    if (v == NULL)
        return 0;
    if (v->p == p)
        return 1;
    if (p < v->p)
        return find(v->l, p);
    else
        return find(v->r, p);
}

ll get(Node* v, ll ct)
{
    if (v == NULL)
        return 0;
    //cout << "!" << v->p << " " << v->c << " " << cnt(v->l) << endl;
    if (cnt(v->l) >= ct)
        return get(v->l, ct);
    if (cnt(v->l) + v->c >= ct)
        return sum(v->l) + v->p * (ct - cnt(v->l));
    else
        return sum(v->l) + v->p * v->c + get(v->r, ct - v->c - cnt(v->l));
}

void print(Node* v)
{
    if (v == NULL)
        return;
    cout << "[";
    print(v->l);
    cout << "]";
    cout << v->p << " " << v->c;
    cout << "{";
    print(v->r);
    cout << "}";
}

int main() {
    iostream::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k, m;
    cin >> n >> k >> m;
    vector<pair<int, pair<ll, ll> > > v;
    Node* root = NULL;
    ll ans = 0;
    for (int i = 0; i < m; i++)
    {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        v.push_back({l, {c, p}});
        v.push_back({r + 1, {-c, p}});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i + 1 < (int)v.size(); i++)
    {
        ll c = v[i].se.fi;
        ll p = v[i].se.se;
        if (c > 0)
        {
            if (find(root, p))
                add(root, c, p);
            else
                root = ins(root, new Node(c, p));
        }
        else
            root = era(root, p, -c);
        //print(root);
        //cout << v[i].first << " " << v[i + 1].first << endl;
        //cout << v[i].first << " " << v[i + 1].first << " " << get(root, k) * (v[i + 1].first - v[i].first) << endl;
        ans += get(root, k) * (v[i + 1].first - v[i].first);
        //cout << endl;
    }
    cout << ans << endl;
    return 0;
}