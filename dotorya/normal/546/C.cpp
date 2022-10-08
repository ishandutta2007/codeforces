//*
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
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
typedef pair <int, ll> pil;
typedef pair <ll, int> pli;

const int IT_MAX = 32768;
const int MOD = 1000000007;
const int INF = 1234567891;
const ll LL_INF = 1234567890123456789ll;

struct Node {
    int n;
    Node* next;
    Node(int x) {
        n = x;
        next = NULL;
    }
};

struct Queue {
    Node* st;
    Node* en;
    Queue() {
        st = NULL;
        en = NULL;
    }
    void push(int x) {
        Node* t = new Node(x);
        if (en == NULL) {
            st = t;
            en = t;
        }
        else {
            en->next = t;
            en = t;
        }
    }

    int pop() {
        Node* t = st;
        st = st->next;
        if (st == NULL) en = NULL;
        int x = t->n;
        free(t);
        return x;
    }
};
int fact(int n) {
    if (n == 1) return 1;
    return n*fact(n - 1);
}
int main() {
    int N, i, t, t1, t2;
    Queue Q1 = Queue();
    Queue Q2 = Queue();
    scanf("%d", &N);
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d", &t2);
        Q1.push(t2);
    }
    scanf("%d", &t);
    for (i = 1; i <= t; i++) {
        scanf("%d", &t2);
        Q2.push(t2);
    }

    int ans = 0, mx = fact(N)+50;
    for (i = 0; i <= mx && Q1.st != NULL && Q2.st != NULL; i++) {
        t1 = Q1.pop();
        t2 = Q2.pop();
        if (t1 > t2) {
            Q1.push(t2);
            Q1.push(t1);
        }
        else {
            Q2.push(t1);
            Q2.push(t2);
        }
    }
    if (Q1.st != NULL && Q2.st != NULL) printf("-1");
    else {
        printf("%d ", i);
        if (Q1.st == NULL) printf("2");
        else printf("1");
    }
    return 0;
}
//*/