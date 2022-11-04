///created by Arsenii Kirillov
#ifdef DEBUG
# define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int) (x).size())

template <typename T>
T input() {
    T res;
    std::cin >> res;
    return res;
}

template <typename IT>
void input_seq(IT b, IT e) {
    std::generate(b, e, input<typename std::remove_reference<decltype(*b)>::type>);
}

#define SZ(vec)         int((vec).size())
#define ALL(data)       data.begin(),data.end()
#define RALL(data)      data.rbegin(),data.rend()
#define TYPEMAX(type)   std::numeric_limits<type>::max()
#define TYPEMIN(type)   std::numeric_limits<type>::min()


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 123;
const ll INFL = 1e18 + 1e6;
mt19937 tw(228);
ll rnd(ll l, ll r) { return tw() % (r - l + 1) + l; }

void solve() {
	int arr[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	if (arr[0] > 0 && arr[1] == 0 && (arr[2] > 0 || arr[3] > 0))
	{
		cout << "NO" << endl;
		return;
	}
	if ((arr[0] > 0 || arr[1] > 0) && arr[2] == 0 && arr[3] > 0)
	{
		cout << "NO" << endl;
		return;
	}
	if (arr[1] < arr[0] - 1)
	{
		cout << "NO" << endl;
		return;
	}
	if (arr[0] + arr[2] < arr[1] - 1)
	{
		cout << "NO" << endl;
		return;
	}
	if (arr[1] + arr[3] < arr[2] - 1)
	{
		cout << "NO" << endl;
		return;
	}
	if (arr[2] < arr[3] - 1)
	{
		cout << "NO" << endl;
		return;
	}
	vector<int> ans1, ans2;
	for (int i = 0; i < 3; i++)
	{
		bool d = 1;
		for (int j = 0; j < i; j++)
			if (arr[j])
				d = 0;
		for (int j = i + 2; j < 4; j++)
			if (arr[j])
				d = 0;
		if (d)
		{
			int j = i + 1;
			if (abs(arr[i] - arr[j]) > 1)
			{
				cout << "NO" << endl;
				return;
			}
			cout << "YES\n";
			if (arr[i] >= arr[j])
			{
				for (int q = 0; q < arr[i]; q++)
				{
					if (q)
						cout << j << " ";
					cout << i << " ";
				}
				if (arr[i] == arr[j])
					cout << j;
				cout << endl;
				return;
			}
			cout << j << " ";
			for (int q = 0; q < arr[i]; q++)
			{
				cout << i << " " << j << " ";
			}
			cout << endl;
			return;
		}
	}
	for (int i = 0; i < 2; i++)
	{
		bool d = 1;
		for (int j = 0; j < i; j++)
			if (arr[j])
				d = 0;
		for (int j = i + 3; j < 4; j++)
			if (arr[j])
				d = 0;
		if (d)
		{
			int j = i + 1;
			int q = i + 2;
			if (abs(arr[j] - (arr[i] + arr[q])) > 1)
			{
				cout << "NO" << endl;
				return;
			}
			cout << "YES" << endl;
			if (arr[i] + arr[q] > arr[j])
			{
				cout << i << " ";
				arr[i]--;
			}
			for (int w = 0; w < arr[j]; w++)
			{
				cout << j << " ";
				if (w < arr[i])
					cout << i << " ";
				else if (w - arr[i] < arr[q])
					cout << q << " ";
			}
			cout << endl;
			return;
		}
	}
	if (arr[0])
	{
		ans1.push_back(0);
		arr[0]--;
		while (arr[0])
		{
			ans1.push_back(1);
			ans1.push_back(0);
			arr[0]--;
			arr[1]--;
		}
	}
	if (arr[3])
	{
		ans2.push_back(3);
		arr[3]--;
		while (arr[3])
		{
			ans2.push_back(2);
			ans2.push_back(3);
			arr[2]--;
			arr[3]--;
		}
	}
	if (abs(arr[1] - arr[2]) > 1 || arr[1] == 0 || arr[2] == 0)
	{
		cout << "NO" << endl;
		return;
	}	
	cout << "YES" << endl;
	if (arr[1] > arr[2])
	{
		cout << 1 << " ";
		arr[1]--;
	}
	for (int i: ans1)
		cout << i << " ";
	for (int i = 0; i < arr[1]; i++)
		cout << "1 2 ";
	for (int i: ans2)
		cout << i << " ";
	if (arr[2] > arr[1])
		cout << 2;
	cout << endl;
}

int main() {
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(15);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t = 1;
    // cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }

#ifdef LOCAL
    cerr << "time: " << clock() * 1000 / CLOCKS_PER_SEC << endl;
#endif
    return 0;
}