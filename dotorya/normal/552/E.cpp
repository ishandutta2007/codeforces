#include <stdio.h>
#include <vector>
#pragma warning(disable:4996)
using namespace std;
typedef long long ll;
const ll PLUS = -1234567869123;
const ll MINUS = -12345678691234;
const ll MULTI = -123456786912345;
const ll DIVIS = -1234567869123456;
const ll LEFT_B = -23456768912345;
const ll RIGHT_B = -234566789123456;
const ll END = -3456789123890;
class bin_tree {
public:
    ll root;
    bin_tree* left;
    bin_tree* right;
    bin_tree(ll a) {
        root = a;
        left = NULL;
        right = NULL;
    }
    bin_tree(bin_tree* a, bin_tree* b, ll c) {
        left = a, right = b;
        root = c;
    }
    bool isLeaf() {
        if (left == NULL && right == NULL) return true;
        else return false;
    }
};
bin_tree* T[5500];
char in[50050];
char tmp2[10000];
ll d[50050];
int Le[50050], Ri[50050];
int bracket_match[50050];
vector <int> tmp;
bin_tree* get_tree(int st, int en) {
    int i = st, j;
    while (i <= en) {
        if (d[i] != LEFT_B) {
            i++;
            continue;
        }
        bin_tree* tmp = get_tree(i + 1, bracket_match[i] - 1);
        for (j = i; j <= bracket_match[i]; j++) {
            T[j] = tmp;
            Le[j] = i, Ri[j] = bracket_match[j];
        }
        i = bracket_match[i] + 1;
        continue;
    }
    i = st;
    while (i <= en) {
        if (d[i] != MULTI && d[i] != DIVIS) {
            i++;
            continue;
        }
        if (Le[i] != -1) {
            i++;
            continue;
        }
        int t1 = Le[i - 1], t2 = Ri[i + 1];
        bin_tree* tmp = new bin_tree(T[t1], T[t2], d[i]);
        for (j = t1; j <= t2; j++) {
            T[j] = tmp;
            Le[j] = t1, Ri[j] = t2;
        }
        i = t2 + 1;
        continue;
    }
    i = st;
    while (i <= en) {
        if (d[i] != PLUS && d[i] != MINUS) {
            i++;
            continue;
        }
        if (Le[i] != -1) {
            i++;
            continue;
        }
        int t1 = Le[i - 1], t2 = Ri[i + 1];
        bin_tree* tmp = new bin_tree(T[t1], T[t2], d[i]);
        for (j = t1; j <= t2; j++) {
            T[j] = tmp;
            Le[j] = t1, Ri[j] = t2;
        }
        i = t2 + 1;
        continue;
    }
    return T[st];
}
void postorder(bin_tree* x) {
    if (x->isLeaf()) {
        printf("%c", x->root);
        return;
    }
    postorder(x->left);
    postorder(x->right);
    printf("%c", x->root);
    return;
}
ll Change(char x) {
    if (x == '+') return PLUS;
    if (x == '-') return MINUS;
    if (x == '*') return MULTI;
    if (x == '/') return DIVIS;
    if (x == '(') return LEFT_B;
    if (x == ')') return RIGHT_B;
    return -1;
}
bool isMark(ll x) {
    if (x != PLUS && x != MINUS && x != MULTI && x != DIVIS && x != LEFT_B && x != RIGHT_B) return false;
    else return true;
}
ll GET_ANS(bin_tree* x) {
    if (x->isLeaf()) return x->root;
    if (x->root == PLUS) {
        return GET_ANS(x->left) + GET_ANS(x->right);
    }
    if (x->root == MINUS) {
        return GET_ANS(x->left) - GET_ANS(x->right);
    }
    if (x->root == MULTI) {
        return GET_ANS(x->left)*GET_ANS(x->right);
    }
    if (x->root == DIVIS) {
        return GET_ANS(x->left) / GET_ANS(x->right);
    }
}

ll get_value() {
    int i, L = 0;
    ll t1, t2;
    //  scanf("%s", tmp2);
    t1 = 0, t2 = 0;
    for (i = 0; tmp2[i] != 0; i++) {
        if (tmp2[i] >= '0' && tmp2[i] <= '9') {
            t1 *= 10;
            t1 += tmp2[i] - '0';
            t2 = 1;
        }
        else {
            if (t2 == 1) d[L++] = t1;
            d[L++] = Change(tmp2[i]);
            t1 = 0;
            t2 = 0;
        }
    }
    d[L++] = t1;
    d[L] = END;
    for (L = 0; d[L] != END; L++) {
        if (!isMark(d[L])) {
            T[L] = new bin_tree(d[L]);
            Le[L] = Ri[L] = L;
        }
        else Le[L] = Ri[L] = -1;
        if (d[L] == LEFT_B) {
            tmp.push_back(L);
        }
        if (d[L] == RIGHT_B) {
            bracket_match[L] = tmp.back();
            bracket_match[tmp.back()] = L;
            tmp.pop_back();
        }
    }
    i = 0;
    bin_tree* ANS_tree = get_tree(0, L - 1);
    return GET_ANS(ANS_tree);
}

vector <int> xpos;
int main() {
    scanf("%s", &in[2]);
    int i, j, k, L;
    in[0] = '1';
    in[1] = '*';
    xpos.push_back(1);
    for (L = 2; in[L] != 0; L++) {
        if (in[L] == '*') xpos.push_back(L);
    }
    in[L] = '*';
    in[L + 1] = '1';
    xpos.push_back(L);
    L += 2;
    ll mx = -1;
    for (i = 0; i < xpos.size(); i++) {
        for (j = i + 1; j < xpos.size(); j++) {
            for (k = 0; k <= xpos[i]; k++) tmp2[k] = in[k];
            tmp2[xpos[i] + 1] = '(';
            for (k = xpos[i] + 1; k < xpos[j]; k++) tmp2[k + 1] = in[k];
            tmp2[xpos[j] + 1] = ')';
            for (k = xpos[j]; k < L; k++) tmp2[k + 2] = in[k];
            ll t = get_value();
            if (mx < t) mx = t;
        }
    }
    printf("%I64d", mx);
    return 0;
}