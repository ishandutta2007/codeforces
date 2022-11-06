#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>


using namespace std;




#define rep(i,k,n)                             for(__typeof(n) i=(k);i<(n);++i)
#define rep2(i,n)                              rep(i,0,n)
#define rrep(i,k,n)                            for(__typeof(n) i=(k)-1;i>=(n);--i)
#define rrep2(i,n)                             rrep(i,n,0)

#define readInt(n)							   scanf("%d", &n);
#define readStr(s)							   scanf("%s", s);


#define ll					long long
#define tkey				ll

#define MOD					(tkey)(1e9+7)
#define HASH_WEIGHT			4
#define MAX_NUM				(tkey)(5e3+7)




tkey val[MAX_NUM];
char s[MAX_NUM];
char src[MAX_NUM];
tkey t[MAX_NUM];
char op[MAX_NUM];
int opCnt, sCnt;



#define PLUS				(tkey)-1
#define MULTI				(tkey)-2


tkey calc(tkey *s, int n)
{
	tkey ans = 0, multiAns = 1;
	int bMulti = 0;

	rep(i, 0, n)
	{
		switch (s[i])
		{
		case PLUS:
			if (bMulti > 0)
			{
				multiAns *= s[i - 1];
				ans += multiAns;
				multiAns = 1;
				bMulti = 0;
			}
			else
				ans += s[i - 1];
			break;
		case MULTI:
			multiAns *= s[i - 1];
			bMulti = 1;
			break;
		default:
			break;
		}
	}
	if (0 == bMulti)
	{
		ans += s[n - 1];
	}
	else
	{
		multiAns *= s[n - 1];
		ans += multiAns;
	}
	return ans;
}

tkey calcVal(tkey *s, int n, int pos)
{
	tkey t1, t2;

	t1 = calc(val, pos);
	t[0] = t1;
	memcpy(t + 1, val + pos, sizeof(tkey) * (n - pos));
	t1 = calc(t, n - pos + 1);
	t2 = calc(val + pos + 1, n - pos - 1);
	memcpy(t, val, sizeof(tkey) * (pos + 1));
	t[pos + 1] = t2;
	t2 = calc(t, pos + 2);

	return max(t1, t2);
}

tkey calcMidVal(tkey *s, int n, int leftPos, int rightPos)
{
	tkey t1;

	t1 = calc(val + leftPos + 1, rightPos - leftPos - 1);
	memcpy(t, val, sizeof(tkey) * (leftPos + 1));
	t[leftPos + 1] = t1;
	memcpy(t + leftPos + 2, val + rightPos, sizeof(tkey) * (n - rightPos));
	return calc(t, n - rightPos + leftPos + 2);
}


int main(int argc, char * argv[])
{
	tkey ans = 0;

	int n;

	// printf("%d\n", MAX_NUM);
	readStr(src);
	n = strlen(src);

	rep(i, 0, n)
	{
		switch (src[i])
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			val[i] = (tkey)(src[i] - '0');
			break;
		case '+':
			val[i] = PLUS;
			break;
		case '*':
			val[i] = MULTI;
			break;
		}
	}

	ans = calc(val, n);
	for (int i = 1; i < n; i += 2)
	{
		if (val[i] == MULTI)
		{
			ans = max(ans, calcVal(val, n, i));
			rep (k, i + 1, n)
			{
				if (val[k] == MULTI)
				{
					ans = max(ans, calcMidVal(val, n, i, k));
					ans = max(ans, calcVal(val, n, k));
				}
			}
		}
	}

	cout << ans << endl;

	return 0;
}