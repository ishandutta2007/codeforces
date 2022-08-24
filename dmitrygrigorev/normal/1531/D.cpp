#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Vertex {
  int unlocked;
  int unknown;
  int unlock;
  int lock;
};

vector<Vertex> rmq;
vector<string> v;

void calc(int i, int index) {
  if (v[index] == "lock") {
    rmq[i] = {-1, -1, -1, index};
  }
  else if (v[index] == "unlock") {
    rmq[i] = {-1, -1, index, -1};
  }
  else {
    rmq[i] = {-1, index, -1, -1};
  }
}

void recalc(Vertex &a, Vertex &b, Vertex &c) {

  a.lock = max(b.lock, c.lock);
  a.unlock = max(b.unlock, c.unlock);

  a.unknown = b.unknown;
  if (c.unknown != -1 && b.lock == -1 && b.unlock == -1) a.unknown = c.unknown;

  a.unlocked = b.unlocked;
  if (c.unlocked != -1) a.unlocked = c.unlocked;
  else if (c.unknown != -1 && b.unlock != -1 && b.unlock > b.lock) a.unlocked = c.unknown;

}

void build(int i, int l, int r) {

  if (r - l == 1) {
    calc(i, l);
    return;
  }

  int mid = (l+r)/2;
  build(2*i+1, l, mid);
  build(2*i+2, mid, r);

  recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);

}

void print() {
  int ans = max(rmq[0].unknown, rmq[0].unlocked);
  cout << v[ans] << '\n';
}

void go(int i, int l, int r, int index) {
  if (r - l == 1) {
    calc(i, l);
    return;
  }

  int mid = (l+r)/2;
  if (index < mid) go(2*i+1, l, mid, index);
  else go(2*i+2, mid, r, index);

  recalc(rmq[i], rmq[2*i+1], rmq[2*i+2]);

}

int main(){
#ifdef LOCAL
	freopen("D_input.txt", "r", stdin);
	//freopen("D_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int n;
  cin >> n;

  v.assign(n + 1, "");
  v[0] = "blue";

  for (int i = 1; i <= n; ++i) cin >> v[i];
  rmq.assign(4*n+4, {});

  build(0, 0, n + 1);
  print();

  int q;
  cin >> q;

  for (int i = 0; i < q; ++i) {
    int index;
    string word;

    cin >> index >> word;
    v[index] = word;

    go(0, 0, n + 1, index);
    print();
  }

}