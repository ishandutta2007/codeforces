#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int kMaxC = 26;
const int kMaxN = 2e6 + 10;

const int kModulo = 51123987;

struct Node
{
    int suff_link;
    int len;

    vector<pair<char, int> > next;
    
    int amount_to_root;
};

string s;

Node tree[kMaxN];
int tree_size;
int max_suff_id;

int GetNext(int v, char c)
{
    for (int i = 0; i < (int) tree[v].next.size(); ++i) {
        if (tree[v].next[i].first == c) {
            return tree[v].next[i].second;
        }
    }
    return 0;
}

void Init()
{
    for (int i = 0; i < kMaxN; ++i) {
        tree[i].next.clear();
    }
    
    tree_size = 2;
    tree[1].suff_link = 1;
    tree[1].len = -1;
    tree[1].amount_to_root = 0;
    
    tree[2].len = 0;
    tree[2].suff_link = 1;
    tree[2].amount_to_root = 0;
    
    max_suff_id = 2;
}

bool AddLetter(int pos)
{
    int cur_suff = max_suff_id;
    int cur_len = tree[cur_suff].len;
    
    while (true) {
        if (pos - cur_len - 1 >= 0 && s[pos] == s[pos - cur_len - 1]) {
            break;
        }
        cur_suff = tree[cur_suff].suff_link;
        cur_len = tree[cur_suff].len;
    }
    
    max_suff_id = GetNext(cur_suff, s[pos]);

    if (max_suff_id) {
        return false;
    }
    
    ++tree_size;
    max_suff_id = tree_size;
    tree[cur_suff].next.push_back(make_pair(s[pos], tree_size));
    tree[tree_size].len = cur_len + 2;
    
    if (cur_suff == 1) {
        tree[tree_size].suff_link = 2;
        tree[tree_size].amount_to_root = 1;
        return true;
    }
    
    while (true) {
        cur_suff = tree[cur_suff].suff_link;
        cur_len = tree[cur_suff].len;
        
        if (pos - cur_len - 1 >= 0 && s[pos] == s[pos - cur_len - 1]) {
            break;
        }
    }
        
    tree[tree_size].suff_link = GetNext(cur_suff, s[pos]);
    tree[tree_size].amount_to_root = 1 + tree[tree[tree_size].suff_link].amount_to_root;
    
    return true;
}

vector<int> GetAmountOfPalindromesAtPos(int n)
{
    vector<int> result(n);
    
    Init();
    
    for (int i = 0; i < n; ++i) {
        AddLetter(i);
        
        result[i] = tree[max_suff_id].amount_to_root;
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    
    Init();
    int n;
    cin >> n;
    
    cin >> s;
    
    vector<int> e = GetAmountOfPalindromesAtPos(n);
    
    reverse(s.begin(), s.end());
    
    vector<int> b = GetAmountOfPalindromesAtPos(n);
    
    int answer = 0;
    for (int i = 0; i < n; ++i) {
        answer += b[i];
        if (answer >= kModulo) {
            answer -= kModulo;
        }
    }
    
    answer = (1LL * answer * (answer - 1) / 2) % kModulo;
    
    reverse(b.begin(), b.end());

    vector<int> sb(n);
    sb[n - 1] = b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        sb[i] = sb[i + 1] + b[i];
        if (sb[i] >= kModulo) {
            sb[i] -= kModulo;
        }
    }
    
    int not_intersect = 0;
    for (int i = 0; i + 1 < n; ++i) {
        not_intersect += (1LL * e[i] * sb[i + 1]) % kModulo;
        if (not_intersect >= kModulo) {
            not_intersect -= kModulo;
        }
    }
    
    answer -= not_intersect;
    if (answer < 0) {
        answer += kModulo;
    }
    
    cout << answer << endl;

    return 0;
}