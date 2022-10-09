#include <bits/stdc++.h>

using namespace std;

#define llong long long 
#define ii pair<int, int>
#define xx first
#define yy second
#define len(v) ((int)v.size())
#define rep(i,n) for (int i = -1; ++i < n; )
#define rep1(i,n) for (int i = 0; i++ < n; )

enum wtype {
  widget, vbox, hbox
};

struct twidget {
  llong sp, br;
  int type;
  llong w, h;
  twidget() {}
  twidget(const string& ty) {
    w = h = -1;
    if (ty[0] == 'W') type = wtype::widget;
    else if (ty[0] == 'V') type = wtype::vbox;
    else type = wtype::hbox;
  }
  vector<twidget*> children;
  void pack() {
    if (w != -1) return;
    w = h = 0;
    if (type == wtype::widget) {
      return ;
    }
    if (len(children) == 0) return;
    rep(i, len(children)) {
      children[i]->pack();
      if (type == wtype::vbox) {
        w = max(w, children[i]->w);
        h += children[i]->h;
      } else {
        h = max(h, children[i]->h);
        w += children[i]->w;
      }
    }
    if (type == wtype::vbox) {
      h += (len(children) - 1) * sp;
    } else {
      w += (len(children) - 1) * sp;
    }
    h += 2 * br;
    w += 2 * br;
  }
};

map<string, twidget> wmap;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  while (n--) {
    string line; getline(cin >> ws, line);
    for (auto& c: line) if (!isalpha(c) and !isdigit(c) and c != '_') c = ' ';
    stringstream ss; ss << line;
    if (isupper(line[0])) {
      string type, name; ss >> type >> name;
      auto& wid = wmap[name] = twidget(type);
      if (wid.type == wtype::widget) ss >> wid.w >> wid.h;
    } else {
      string name, med, par; ss >> name >> med;
      if (med[0] == 'p') ss >> par, wmap[name].children.push_back(&wmap[par]);
      else  if (med == "set_spacing") ss >> wmap[name].sp;
      else ss >> wmap[name].br;
    }
  }
  for (auto& u: wmap) {
    u.yy.pack();
    cout << u.xx << ' ' << u.yy.w << ' ' << u.yy.h << '\n';
  }
  
  return 0;
}