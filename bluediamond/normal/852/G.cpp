#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct trie
{
    int cnt;
    int last;
    trie* kids[5];
    trie()
    {
        cnt = last = 0;
        for (int i = 0; i < 5; i++)
        {
            kids[i] = 0;
        }
    }
};

trie* root = new trie;
int n;
int q;
int id;
int sol;
string p;

void bkt(int i, trie* now)
{
    if (i == (int) p.size())
    {
        if (now->last != id)
        {
            now->last = id;
            sol += now->cnt;
        }
    }
    else
    {
        if (p[i] == '?')
        {
            bkt(i + 1, now);
            for (int x = 0; x < 5; x++)
            {
                if (now->kids[x])
                {
                    bkt(i + 1, now->kids[x]);
                }
            }
        }
        else
        {
            int x = p[i] - 'a';
            if (now->kids[x])
            {
                bkt(i + 1, now->kids[x]);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        trie* now = root;
        for (auto &ch : s)
        {
            int x = ch - 'a';
            if (!now->kids[x])
            {
                now->kids[x] = new trie;
            }
            now = now->kids[x];
        }
        now->cnt++;
    }
    for (int i = 1; i <= q; i++)
    {
        sol = 0;
        cin >> p;
        id = i;
        bkt(0, root);
        cout << sol << "\n";
    }

}