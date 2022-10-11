#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <cassert>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int int64;
typedef long double double80;

const int INF = (1 << 29) + 5;
const int64 LLINF = (1ll << 59) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;
const int MAX_N = 1000 * 1000 + 5;

struct node
{
	int value;
	int size;
	int y;
	node *l;
	node *r;

	node(int _value)
	{
		value = _value;
		y = ((rand() << 15) | rand());
		size = 1;
		l = nullptr;
		r = nullptr;
	}
};

void print(node *t)
{
	if (t == nullptr)
	{
		return;
	}
	else
	{
		print(t->l);
		printf("%d ", t->value);
		print(t->r);
	}
}

int get_size(node *t)
{
	if (t == nullptr)
	{
		return 0;
	}
	else
	{
		return t->size;
	}
}

void upd(node* &t)
{
	t->size = get_size(t->l) + get_size(t->r) + 1;
}

node* merge(node *t1, node *t2)
{
	if (t1 == nullptr)
	{
		return t2;
	}
	else if (t2 == nullptr)
	{
		return t1;
	}
	else
	{
		if (t1->y > t2->y)
		{
			t1->r = merge(t1->r, t2);
			upd(t1);
			return t1;
		}
		else
		{
			t2->l = merge(t1, t2->l);
			upd(t2);
			return t2;
		}
	}
}

void split(node *t, node* &t1, node* &t2, int x)
{
	if (t == nullptr)
	{
		t1 = nullptr;
		t2 = nullptr;
	}
	else
	{
		if (t->value < x)
		{
			split(t->r, t->r, t2, x);
			t1 = t;
		}
		else
		{
			split(t->l, t1, t->l, x);
			t2 = t;
		}
		upd(t);
	}
}


struct mm
{
	int type;
	int x;
	int time;
	int real_time;

	mm()
	{
	}

	mm(int _type, int _x, int _time)
	{
		type = _type;
		x = _x;
		time = _time;
	}
};

struct ans
{
	int time;
	int x;

	ans()
	{

	}

	ans(int _x, int _time)
	{
		x = _x;
		time = _time;
	}
};

bool cmp(const mm &a, const mm &b)
{
	return a.time < b.time;
}

bool cmp2(const ans &a, const ans &b)
{
	return a.time < b.time;
}

int n;
mm arr[MAX_N];
node* at_number[MAX_N];
node* del_number[MAX_N];
vector<ans> answer;
set<int> xx;
map<int, int> new_of;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d %d", &arr[i].type, &arr[i].time, &arr[i].x);
		xx.insert(arr[i].x);
		arr[i].real_time = i;
	}

	int gg = 0;
	for (auto it = xx.begin(); it != xx.end(); ++it)
	{
		new_of[*it] = gg;
		++gg;
	}
	for (int i = 0; i < n; ++i)
	{
		arr[i].x = new_of[arr[i].x];
	}
	for (int i = 0; i < gg; ++i)
	{
		at_number[i] = nullptr;
		del_number[i] = nullptr;
	}

	sort(arr, arr + n, cmp);

	node *t1, *t2, *t3, *t4;
	for (int i = 0; i < n; ++i)
	{
		if (arr[i].type == 1)
		{
			split(at_number[arr[i].x], t1, t2, arr[i].real_time);
			at_number[arr[i].x] = merge(merge(t1, new node(arr[i].real_time)), t2);
		}
		else if (arr[i].type == 2)
		{
			split(del_number[arr[i].x], t1, t2, arr[i].real_time);
			del_number[arr[i].x] = merge(merge(t1, new node(arr[i].real_time)), t2);
		}
		else
		{
			split(at_number[arr[i].x], t1, t2, arr[i].real_time);
			split(del_number[arr[i].x], t3, t4, arr[i].real_time);
			answer.push_back(ans(get_size(t1) - get_size(t3), arr[i].real_time));
			at_number[arr[i].x] = merge(t1, t2);
			del_number[arr[i].x] = merge(t3, t4);
		}
	}

	sort(answer.begin(), answer.end(), cmp2);

	for (int i = 0; i < answer.size(); ++i)
	{
		printf("%d\n", answer[i].x);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}