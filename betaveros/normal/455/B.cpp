#include <cstdio>
#include <map>
#include <cctype>
#include <utility>
using namespace std;

struct Node {
    map<char, Node*> children;
    int win;
    int lose;
    Node() {}
    Node * getChild(char c) {
        if (children.count(c)) return children[c];
        Node * node = new Node();
        children[c] = node;
        return node;
    }
    void dump() {
        printf("%d %d\n", win, lose);
        for (map<char, Node*>::iterator it = children.begin();
                    it != children.end();
                    it++) {
                pair<const char, Node*> & p = *it;
                printf("start %c\n", p.first);
                p.second->dump();
                printf("end %c\n", p.first);
        }
    }
    void build(bool turn) {
        if (children.size()) {
            win = lose = !turn;
            for (map<char, Node*>::iterator it = children.begin();
                    it != children.end();
                    it++) {
                pair<const char, Node*> & p = *it;
                p.second->build(!turn);
                if (p.second->win == turn) win = turn;
                if (p.second->lose == turn) lose = turn;
            }
        } else {
            win = !turn;
            lose = turn;
        }
    }
};
Node * root = new Node();
int main() {
    int n, k;
    scanf("%d %d ", &n, &k);
    char buf[100005];
    for (int i = 0; i < n; i++) {
        fgets(buf, 100002, stdin);
        Node * cur = root;
        for (int j = 0; isalpha(buf[j]); j++) {
            cur = cur->getChild(buf[j]);
        }
    }
    root->build(0);
    //root->dump();
    
    if (root->win) printf("Second\n");
    else if (k == 1) printf("First\n");
    else if (!root->lose) printf("First\n");
    else if (k & 1) printf("First\n"); else printf("Second\n");
    return 0;
}