//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <time.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#pragma warning(disable:4996)
using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <char, char> pcc;
typedef pair <int, char> pic;
typedef set <int>::iterator siit;
typedef set <ll>::iterator slit;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

class Trie {
public:
    Trie() {
        Trie(0);
    }
    Trie(int x) {
        lvl = x;
        for (int i = 0; i < 26; i++) child[i] = NULL;
    }
    void insert(char* x) {
        if (x[lvl] == 0) return;
        int t = x[lvl] - 'a';
        if (child[t] == NULL) child[t] = new Trie(lvl + 1);
        child[t]->insert(x);
        return;
    }
    int Trav() {
        for (int i = 0; i < 26; i++) {
            if (child[i] == NULL) continue;
            if (child[i]->Trav() == 2) return 1;
        }
        return 2;
    }
    int LoseTrav() {
        int i;
        for (i = 0; i < 26; i++) {
            if (child[i] != NULL) break;
        }
        if (i == 26) return 1;
        for (i = 0; i < 26; i++) {
            if (child[i] == NULL) continue;
            if (child[i]->LoseTrav() == 2) return 1;
        }
        return 2;
    }
    int lvl;
    Trie* child[26];
};

char T[100050];
int main() {
    Trie* root = new Trie(0);
    int N, K, i, j;
    scanf("%d %d", &N, &K);
    for (i = 1; i <= N; i++) {
        scanf("%s", T);
        root->insert(T);
        for (j = 0; T[j] != 0; j++) T[j] = 0;
    }

    // Traversal
    if (root->Trav() == 2) {
        printf("Second");
        return 0;
    }

    if (root->LoseTrav() == 1) {
        printf("First");
        return 0;
    }

    if (K % 2 == 1) printf("First");
    else printf("Second");
    return 0;
}

//*/