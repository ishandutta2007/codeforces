#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int MAGIC = 300;
const int BLOCKS = 160000/MAGIC;

vector<int> tree;
vector<int> leave_block;

int add[BLOCKS];
int cnt[BLOCKS];

int n;

void recalc(int block) {
  for (int i = block * MAGIC; i < min(n, (block + 1) * MAGIC); ++i) {
    tree[i] = max(0, tree[i] - add[block]);
  }
  add[block] = 0;

  for (int i = block * MAGIC; i < min(n, (block + 1) * MAGIC); ++i) {
    int W = tree[i];
    if (W < block * MAGIC) leave_block[i] = W;
    else leave_block[i] = leave_block[W];
  }

}

int layer(int x) {
  return x/MAGIC;
}

int go_outer(int x) {
  return max(0, leave_block[x] - add[layer(x)]);
}

int go(int x) {
  return max(0, tree[x] - add[layer(x)]);
}

int main(){
#ifdef LOCAL
	freopen("H_input.txt", "r", stdin);
	//freopen("H_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

  int q;
  cin >> n >> q;

  tree.assign(n, 0);
  for (int i = 1; i < n; ++i) {
    cin >> tree[i];
    tree[i]--;
  }

  leave_block.assign(n, 0);

  for (int i = 0; i * MAGIC < n; ++i) {
    recalc(i);
  }

  for (int i = 0; i < q; ++i) {
    int tp;
    cin >> tp;

    //cout << " === " << go_outer(4) << endl;

    if (tp == 1) {
      int l, r, x;
      cin >> l >> r >> x;
      l--, r--;
      for (int j = 0; j * MAGIC < n; ++j) {
        int L = j*MAGIC, R = min(n, (j+1)*MAGIC) - 1;
        
        int pl = max(L, l), pr = min(R, r);
        if (pl > pr) continue;
        if (pl != L || pr != R || cnt[j] <= MAGIC) {
          if (pl == L && pr == R) {
            cnt[j]++;
            add[j]+=x;
            add[j] = min(add[j], (int) 1e8);
          }
          else {
            for (int e = pl; e <= pr; ++e) tree[e] = max(0, tree[e] - x);
          }
        //cout << " ??? " << j << endl;
          recalc(j);
          //cout << leave_block[3] << " " << tree[3] << " " << pl <<  " " << pr  << endl;
        } 
        else {
          add[j]+=x;
          add[j] = min(add[j], (int) 1e8);
        }

      }
    }

    else {
      int u, v;
      cin >> u >> v;

      u--, v--;
      while (true) {
        if (u == v) break;
        //cout << u << " " << v << endl;
        //cout << go_outer(u) << " " << go_outer(v) << endl;
        if (layer(u) < layer(v)) {
          swap(u, v);
        }
        if (layer(u) > layer(v)) {
          u = go_outer(u);
        }
        else {
          int A = go_outer(u), B = go_outer(v);
          if (A!=B) {
            u = A, v = B;
          }
          else {
            while (u != v) {
              if (u > v) u = go(u);
              else v = go(v); 
            }
          }
        }
      }

      cout << u+1 << '\n';


    }
  }


}