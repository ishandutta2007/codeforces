#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define MAXN 300005

struct trie{

    struct node{
        node *edge[26];
        node() { for(int i=0;i<26;i++) edge[i]=0; }
    }*root;

    trie() { root=new node(); }

    void insert(string s)
    {
        node *t=root;
        for(auto v : s)
        {
            int x=v-'a';
            if(!(t->edge[x]))
                t->edge[x]=new node();
            t=t->edge[x];
        }
    }

    bool marcelo(string s)
    {
        node *t=root;
        for(int i=0;i<s.size();i++)
        {
            int x=s[i]-'a';
            for(int j=0;j<26;j++)
                if(x!=j && t->edge[j])
                {
                    node *tt=t->edge[j];
                    int ii=i+1;
                    while(ii<s.size() && tt->edge[s[ii]-'a'])
                    {
                        tt=tt->edge[s[ii]-'a'];
                        ii++;
                    }
                    if(ii==s.size())
                        return 1;
                }
            if(!(t->edge[x]))
                break;
            t=t->edge[x];
        }
        return 0;
    }

}t[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m;
    cin >> n >> m;
    string s;
    for(int i=0;i<n;i++)
    {
        cin >> s;
        if(s.size()<MAXN)
            t[s.size()].insert(s);
    }
    for(int i=0;i<m;i++)
    {
        cin >> s;
        if(s.size()<MAXN && t[s.size()].marcelo(s))
            db("YES")
        else
            db("NO")
    }

    return 0;
}