#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <stdint.h>
#include <assert.h>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::vector;
using std::string;

using std::pair;
using std::make_pair;

using std::min;
using std::max;


template <typename T>
inline T input()
{
	T ans;
	cin >> ans;
	return ans;
}

void display(const vector<char>& num)
{
	for (auto it = num.rbegin(); it != num.rend(); ++it)
		cout << *it;
	endl(cout);
}

void inc_task(vector<char>& num, uint32_t delta)
{
	uint32_t pos = 0;
	while (delta != 0 and pos < num.size())
	{
		if (delta <= uint32_t('9' - num[pos]))
		{
			num[pos] += delta;
			return;
		}
		// delta > '9' - num[pos]
		delta -= '9' - num[pos];
		num[pos] = '9';
		++pos;
	}
	while (delta != 0)
	{
		if (delta <= 9)
		{
			num.push_back('0' + delta);
			return;
		}
		num.push_back('9');
		delta -= 9;
	}
}

void dec_task(vector<char>& num, uint32_t delta)
{
	uint32_t s = num[0] - '0';
	num[0] = '0';
	uint32_t pos = 1;
	while (pos < num.size() and not (num[pos] != '9' and s >= delta + 1))
	{
		s += num[pos] - '0';
		num[pos] = '0';
		++pos;
	}
	uint32_t new_delta = s - (delta + 1);
	if (pos == num.size())
		num.push_back('1');
	else
		++num[pos];
	if (new_delta != 0)
		inc_task(num, new_delta);
}

void waste_task(vector<char>& num)
{
	dec_task(num, 0);
}


int main()
{
	uint32_t n = input<uint32_t>();
	assert(n != 0);
	
	// 0             n
	// (  . ).
	vector<char> num;
	uint32_t b_prev = input<uint32_t>();
	uint32_t b0 = b_prev;
	while (true)
	{
		if (b0 <= 9)
		{
			num.push_back('0' + b0);
			break;
		}
		num.push_back('9');
		b0 -= 9;
	}
	
	display(num);
	
	for (uint32_t i = 1; i < n; i++)
	{
		uint32_t b_cur = input<uint32_t>();
		if (b_cur > b_prev)
			inc_task(num, b_cur - b_prev);
		if (b_cur == b_prev)
			waste_task(num);
		if (b_cur < b_prev)
			dec_task(num, b_prev - b_cur);
		
		b_prev = b_cur;
		display(num);
	}
	
	return 0;
}