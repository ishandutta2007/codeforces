#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> VI;
typedef vector<VI> VVI;
typedef pair<ll, ll> ii;

struct node {
    ll value;
    node* left;
    node* right;
};

vector<ii> v;

void traverse(node* cur, ll ip, int h) {
    if (cur == NULL) return;
    if (cur->value == 1) {
        v.push_back({ip, h});
    }
    else if (cur-> value == 3) {
        traverse(cur->left, ip, h + 1);
        traverse(cur->right, ip + (1 << (31 - h)), h + 1);
    }
}

int color(bool& ok, ll ip, int h, node* cur) {
    int a = 0, b = 0;
    if (cur->left != NULL) {
        a = color(ok, ip, h + 1, cur->left);
    }
    if (cur->right != NULL) {
        b = color(ok, ip + (1 << (31 - h)), h + 1, cur->right);
    }
    int c = a|b;
    if (cur->value == 1 and c&2) ok = false;
    else if (cur->value == 2 and c&1) ok = false;
    else if (cur->value == 0) cur->value = c;
    return cur->value;
}

void init(node* cur) {
    cur->left = cur->right = NULL;
    cur->value = 0;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
    node* root = new node;
    init(root);
    int n;
    cin >> n;
    bool ok = true;
    for (int i = 0; i < n; ++i) {
        char s, c;
        cin >> s;
        ll value = 0;
        for (int j = 0; j < 4; ++j) {
            value *= 256;
            ll a;
            cin >> a;
            value += a;
            if (j != 3) cin >> c;
        }
        ll mask = 32;
        if (cin.peek() == '/') {
            cin >> c;
            cin >> mask;
        }
        ll h = 0;
        node* cur = root;
        while (h < mask) {
            if (value&(1 << (31 - h))) {
                if (cur->right == NULL) {
                    cur->right = new node;
                    init(cur->right);
                }
                cur = cur->right;
            }
            else {
                if (cur->left == NULL) {
                    cur->left = new node;
                    init(cur->left);
                }
                cur = cur->left;
            }
            ++h;
        }
        if (cur->value == 1 and s == '+') ok = false;
        else if (cur->value == 2 and s == '-') ok = false;
        else if (s == '+') cur->value = 2;
        else cur->value = 1;
    }
    color(ok, 0, 0, root);
    if (!ok) {
        cout << -1 << endl;
        return 0;
    }
    traverse(root, 0, 0);
    cout << v.size() << endl;
    for (int i = 0; i < v.size(); ++i) {
        ll a = (v[i].first&0xff000000) >> 24;
        ll b = (v[i].first&0xff0000) >> 16;
        ll c = (v[i].first&0xff00) >> 8;
        ll d = (v[i].first&0xff);
        cout << a << "." << b << "." << c << "." << d << "/" << v[i].second << endl;
    }
}