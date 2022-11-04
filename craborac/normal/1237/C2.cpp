#include <bits/stdc++.h>

using namespace std;

struct kek
{
	int x, y, z, i;
	kek(int x_ = 0, int y_ = 0, int z_ = 0, int i_ = 0): x(x_), y(y_), z(z_), i(i_) {};
	bool operator < (const kek a)const
	{
		if (x != a.x)
			return x < a.x;
		if (y != a.y)
			return y < a.y;
		return z < a.z;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<kek> mas(n);
	vector<pair<int, int> > ans;
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i].x >> mas[i].y >> mas[i].z;
		mas[i].i = i + 1;
	}
	sort(mas.begin(), mas.end());
	vector<kek> v;
	for (int i = 0; i < n; i++)
	{
		if (v.size() > 0 && v.back().x == mas[i].x && v.back().y == mas[i].y)
		{
			ans.push_back({v.back().i, mas[i].i});
			v.pop_back();
		}
		else
			v.push_back(mas[i]);
	}
	vector<kek> w;
	for (auto i: v)
	{
		if (w.size() > 0 && w.back().x == i.x)
		{
			ans.push_back({w.back().i, i.i});
			w.pop_back();
		}
		else
			w.push_back(i);
	}
	int last = -1;
	for (auto i: w)
	{
		if (last == -1)
			last = i.i;
		else
		{
			ans.push_back({last, i.i});
			last = -1;
		}
	}
	for (auto p: ans)
		cout << p.first << " " << p.second << "\n";
	return 0;
}