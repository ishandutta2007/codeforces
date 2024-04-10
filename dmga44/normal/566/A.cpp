#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 100005

bool mk[MAXN][2];
vector<int> res;
int bla;

struct trie{

    struct node{
        node *edge[26];
        vector<int> v[2];
        node() { for(int i=0;i<26;i++) edge[i]=0; }
    }*root;

    trie() { root=new node(); }

    void insert(string s,int xx,int tt)
    {
        node *t=root;
        root->v[tt].push_back(xx);
        for(auto y : s)
        {
            int x=y-'a';
            if(!(t->edge[x]))
                t->edge[x]=new node();
            t=t->edge[x];
            t->v[tt].push_back(xx);
        }
    }

    void marcelo(node *u)
    {
        for(int i=0;i<26;i++)
            if(u->edge[i])
                marcelo(u->edge[i]);

        int i=0,j=0;
        for(auto y : (u->v[0]))
            if(mk[y][0])
                bla++;
        while(i<u->v[0].size() && j<u->v[1].size())
        {
            if(!mk[u->v[0][i]][0] && !mk[u->v[1][j]][1])
            {
                res.push_back((u->v[0][i])+1);
                res.push_back((u->v[1][j])+1);
                mk[u->v[0][i]][0]=1;
                mk[u->v[1][j]][1]=1;
                i++,j++;
            }
            while(i<(u->v[0].size()) && mk[u->v[0][i]][0])
                i++;
            while(j<(u->v[1].size()) && mk[u->v[1][j]][1])
                j++;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    string s;
    trie t;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        t.insert(s,i,0);
    }

    for(int i=0;i<n;i++)
    {
        cin >> s;
        t.insert(s,i,1);
    }

    t.marcelo(t.root);

    db(bla)
    for(int i=0;i<res.size();i++)
    {
        cout << res[i] << ' ';
        if(i&1)
            cout << '\n';
    }

    return 0;
}