#include <bits/stdc++.h>

#define ll long long

const int MAX_N = 3e5 + 10 , mod = 1e9 + 7 ;

struct Node {
    int len , cnt[3] ;
    Node *next[26] , *link ;
}sam[MAX_N << 1] ;

std::vector<Node*> nde[MAX_N] ;

char s[3][MAX_N] ;
Node *root , *last ;
int tot , ans[MAX_N] ;

void extend(int c) {
    Node *p = last , *cur ;
    if (p->next[c]) {
        Node *q = p->next[c] ;
        if (p->len + 1 == q->len) cur = q ;
        else {
            cur = &sam[tot++] ;
            *cur = *q ; cur->len = p->len + 1 ;
            for (; p && p->next[c] == q ; p = p->link) p->next[c] = cur ;
            q->link = cur ;
        }
    }
    else {
        cur = &sam[tot++] ; cur->len = last->len + 1 ;
        for (; p && !p->next[c] ; p = p->link) p->next[c] = cur ;

        if (!p) cur->link = root ;
        else {
            Node *q = p->next[c] ;
            if (p->len + 1 == q->len) cur->link = q ;
            else {
                Node *clone = &sam[tot++] ;
                *clone = *q ; clone->len = p->len + 1 ;
                for (; p && p->next[c] == q ; p = p->link) p->next[c] = clone ;
                cur->link = q->link = clone ;
            }
        }
    }
    last = cur ;
}

int main() {
    root = &sam[tot++] ;
    root->link = NULL ;
    root->len = root->cnt[0] = root->cnt[1] = root->cnt[2] = 0 ;

    int ma = 0 , mi = MAX_N ;
    for (int i = 0 ; i < 3 ; ++i) {
        scanf("%s" , s[i]) ;
        int n = strlen(s[i]) ;
        last = root ; ma = std::max(n , ma) ; mi = std::min(n , mi) ;
        for (int j = 0 ; j < n ; ++j)
            extend(s[i][j] - 'a') ;
    }
    for (int i = 0 ; i < 3 ; ++i) {
        Node *p = root ;
        int n = strlen(s[i]) ;
        for (int j = 0 ; j < n ; ++j) {
            p = p->next[s[i][j] - 'a'] ;
            ++p->cnt[i] ;
        }
    }

    for (int i = 1 ; i < tot ; ++i) nde[sam[i].len].push_back(&sam[i]) ;
    for (int i = ma ; i ; --i)
        for (auto &x : nde[i])
            for (int c = 0 ; c < 3 ; ++c) x->link->cnt[c] += x->cnt[c] ;
    
    for (int i = 1 ; i < tot ; ++i) {
        int L = sam[i].link->len + 1 , R = sam[i].len ,
            res = (ll)sam[i].cnt[0] * sam[i].cnt[1] % mod * sam[i].cnt[2] % mod ;
        (ans[L] += res) %= mod ; (ans[R + 1] += (mod - res)) %= mod ;
    }
    for (int i = 1 ; i <= mi ; ++i) {
        (ans[i] += ans[i - 1]) %= mod ;
        printf("%d " , ans[i]) ;
    }

    return 0 ;
}