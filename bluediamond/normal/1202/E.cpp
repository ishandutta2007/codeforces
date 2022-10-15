#include <bits/stdc++.h>

using namespace std;

//#define int long long
typedef long long ll;
const int N = (int) 2e5 + 7;
//#define int long long


struct node
{
  int sum;
  node* k[26];
  node* to;
  int fr;
  node()
  {
    for (int i = 0; i < 26; i++)
    {
      k[i] = 0;
    }
    to = 0;
    sum = 0;
    fr = 0;
  }
};

void print(node* a)
{
  for (int i = 0; i < 26; i++)
  {
    if (a->k[i])
    {
      print(a->k[i]);
    }
  }
}

node* root = new node;
int a[N], b[N];
string cop[N];


signed main()
{
  ios::sync_with_stdio(0); cin.tie(0);

  ///freopen ("input", "r", stdin);

  string str;
  cin >> str;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    string s;
    cin >> s;
    cop[i] = s;
    node* cur = root;
    for (auto &ch : s)
    {
      int x = ch - 'a';
      if (!cur->k[x])
      {
        cur->k[x] = new node;
      }
      cur = cur->k[x];
    }
    cur->fr++;
  }
  queue<node*> q;
  vector<node*> ord;
  q.push(root);
  while (!q.empty())
  {
    node* cur = q.front();
    q.pop();
    ord.push_back(cur);
    for (int i = 0; i < 26; i++)
    {
      if (cur->k[i])
      {
        q.push(cur->k[i]);
      }
    }
  }
  root->to = root;
  for (auto &cur : ord)
  {
    for (int i = 0; i < 26; i++)
    {
      if (cur->k[i])
      {
        node* now = cur->to;
        while (now != root && !now->k[i])
        {
          now = now->to;
        }
        if (cur != root && now->k[i])
        {
          now = now->k[i];
        }
        cur->k[i]->to = now;
      }
    }
  }
  for (auto &cur : ord)
  {
    cur->sum = cur->fr + cur->to->sum;
  }
  node* cur = root;
  int ind = 0;
  for (auto &ch : str)
  {
    int i = ch - 'a';
    while (cur != root && !cur->k[i])
    {
      cur = cur->to;
    }
    if (cur->k[i])
    {
      cur = cur->k[i];
    }
    a[++ind] = cur->sum;
  }
  root = new node;

  reverse(str.begin(), str.end());
  for (int i = 1; i <= n; i++)
  {
    string s = cop[i];
    reverse(s.begin(), s.end());
    node* cur = root;
    for (auto &ch : s)
    {
      int x = ch - 'a';
      if (!cur->k[x])
      {
        cur->k[x] = new node;
      }
      cur = cur->k[x];
    }
    cur->fr++;
  }
  assert(q.empty());
  ord.clear();
  q.push(root);
  while (!q.empty())
  {
    node* cur = q.front();
    q.pop();
    ord.push_back(cur);
    for (int i = 0; i < 26; i++)
    {
      if (cur->k[i])
      {
        q.push(cur->k[i]);
      }
    }
  }
  root->to = root;
  for (auto &cur : ord)
  {
    for (int i = 0; i < 26; i++)
    {
      if (cur->k[i])
      {
        node* now = cur->to;
        while (now != root && !now->k[i])
        {
          now = now->to;
        }
        if (cur != root && now->k[i])
        {
          now = now->k[i];
        }
        cur->k[i]->to = now;
      }
    }
  }
  for (auto &cur : ord)
  {
    cur->sum = cur->fr + cur->to->sum;
  }
  cur = root;
  ind = (int) str.size();
  for (auto &ch : str)
  {
    int i = ch - 'a';
    while (cur != root && !cur->k[i])
    {
      cur = cur->to;
    }
    if (cur->k[i])
    {
      cur = cur->k[i];
    }
    b[ind--] = cur->sum;
    //cout << cur->sum << " ";
  }
  ll sol = 0;
  for (int i = 1; i < (int) str.size(); i++)
  {
    sol += (ll) a[i] * b[i + 1];
  }
  cout << sol << "\n";
  return 0;
}