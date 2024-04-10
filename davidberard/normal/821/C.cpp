/* Codeforces 420
 *
 */
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <utility>
#include <vector>
#include <set>

#define ADD 1
#define REMOVE 2

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> pii;
typedef vector<int> Vint;

struct cmd{
	int type;
	int streak;
	int val;
};

int N;

int main()
{
	cin >> N;
	vector<cmd> commands(N*2);
	string s;
	int val;
	int rcounter = 1;
	for(int i=0;i<2*N;++i)
	{
		cin >> s;
		cmd &com = commands[i];
		if(s == "add")
		{
			cin >> val;
			com.type = ADD;
			com.val = val;
		}
		else
		{
			com.type = REMOVE;
			com.val = rcounter;
			com.streak = 1;
			++rcounter;
		}
	}

	rcounter = 1;
	int pos = -1;
	bool isStreak = false;
	for(int i=0;i<2*N;++i)
	{
		if(commands[i].type != REMOVE)
			isStreak = false;

		if(isStreak && commands[i].type == REMOVE)
			commands[pos].streak++;

		if(commands[i].type == REMOVE)
			isStreak = true, pos=i;
	}

	vector<int> sta(N);
	pos = 0;
	int reorderings = 0;
	int heightOrderedTo = 0;
	rcounter = 1;
	for(int i=0;i<2*N;++i)
	{
		if(commands[i].type == ADD)
			sta[pos++] = commands[i].val;
		else if(commands[i].type == REMOVE)
		{
			if(pos-1 <= heightOrderedTo)
			{
				--pos, --heightOrderedTo;
				continue;
			}
			else if(sta[pos-1] == commands[i].val)
			{
				--pos;
				continue;
			}
			else
			{
				--pos; heightOrderedTo = pos-1; reorderings++;
				continue;
			}
		}
	}

	cout << reorderings << endl;
	

	return 0;
}