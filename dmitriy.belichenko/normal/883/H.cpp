#include <bits/stdc++.h>
#include <time.h>

using namespace std;

const int mod = (int) 1e9 + 7;

void add(int & x, int y) {
	if ((x += y) >= mod) {
		x -= mod;
    }
}

int sum(int x, int y) {
    add(x, y);
    return x;
}

int mult(int x, int y) {
    return (long long) x * y % mod;
}

int power(int x, long long p) {
    int res = 1;
    while (p) {
      if (p & 1) {
        res = mult(res, x);
      }
      x = mult(x, x);
      p >>= 1;
    }
    return res;
}

int inv(int x) {
  return power(x, mod - 2);
}

const int inf = (int) 1.01e9;
const long double eps = 1e-8;
const long double pi = acos(-1.0L);
const int maxn = 1e5 + 100;

int used[1003][30];
int told[30];
vector<int> pos, good;

void solve() {
    int n;
    cin >> n;
    int ans = n;
    string s;
    cin >> s;
    //int k = 0;
    map<char , int> cnt;
    for(int i = 0; i < n; i++)
    {
        cnt[s[i]]++;
    }
    vector<int> div;
    for(int i = 1; i * i <= n; i++ )
    {
        if(n % i == 0)
        {
            div.push_back(i);
            if(n / i != i)
            div.push_back(n / i);
        }
    }
    int num = 0;
    sort(div.begin() , div.end());
    for(auto i : cnt)
    {
        if(i.second % 2) num++;
    }
    if(num == 0) {
        deque<char> res;
        while(cnt.size())
        {
            map<char , int>::iterator tmp = cnt.begin();
            if(tmp->second >= 2)
                {
                    res.push_back(tmp->first);
                    res.push_front(tmp->first);
                }
                cnt[tmp->first] -= 2;
                //   cout << cnt[tmp->fst] << "\n";
                if(cnt[(*cnt.begin()).first] <= 0) cnt.erase(cnt.begin());
        }
        ans = 1;
        cout << 1 << '\n';
      //  for(int i = 0; i < ans; i++) {
            for(auto c : res) cout << c;
            cout << " ";
        //}
        return;
    }
  //  cout << num << "\n";
    for(int i  = 0; i < div.size(); i++)
    {
        if(div[i] < num) continue;
        int tmp = n - div[i];
        if( (div[i] - num ) % 2) continue;
        if(tmp % 2) continue;
        tmp = tmp / 2;
        if( tmp % div[i] == 0 )
        {
            ans = min(div[i] , ans);
            break;
        }
    }
    int u = 0;
    vector<deque<char>> res(ans);
    int j = 0;
    for(auto i : cnt)
    {
        if(i.second % 2)
        {
            res[j++].push_back(i.first);
            u++;
            cnt[i.first]--;
        }
    }
    for (auto i = cnt.begin(); i != cnt.end();) {
        if (i->second == 0) {
            cnt.erase(i++);
        } else {
            i++;
        }
    }
    while(j < ans)
    {
        auto tmp = *cnt.begin();
        res[j++].push_back(tmp.first);
        res[j++].push_back(tmp.first);
        if(tmp.second == 2) cnt.erase(cnt.begin());
        else
            cnt[tmp.first] -= 2;
    }
    while(cnt.size())
    {
        for(int i = 0; i < ans; i++)
        {
            auto tmp = *cnt.begin();
            res[i].push_back(tmp.first);
            res[i].push_front(tmp.first);
            if(tmp.second == 2) cnt.erase(cnt.begin());
            else
                cnt[tmp.first] -= 2;
        }
    }
    cout << ans << '\n';
    for(int i = 0; i < ans; i++) {
        for(auto c : res[i]) cout << c;
        cout << " ";
    }
    cout << endl;
}

void precalc() {
}

void clear() {
}

// #define FNAME "local"
// #define DEBUG

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout.precision(8);
    srand(time(0));
    cout << fixed;
    precalc();
#ifdef FNAME
 	assert(freopen(FNAME".in", "r", stdin));
    freopen(FNAME".out", "w", stdout);
#endif
	int task_count = 1;
	// cin >> task_count;
    for (int i = 1; i <= task_count; ++i) {
        // cout << "Case #" << i << ": ";
		solve();
#ifdef DEBUG
		cout << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	    clear();
	}
    return 0;
}