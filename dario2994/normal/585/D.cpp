#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define pb	push_back

#if DEBUG && !ONLINE_JUDGE
	ifstream input_from_file("input.txt");
	#define cin input_from_file
#endif

const int MAXN = 26;
const int HN = 3;
int att[MAXN][HN];

typedef pair<int,vi> ch;
typedef pair<ii,ch> lch;// ( (d1, d2),  (sum, choice) )
vector<lch> fh;
map<ii,ch> sh;

bool to_fh;
void exploop(int s, int e, int l, const vi& attval, vi& partch)
{
	if (s <= e)
	{
		for (int i=0; i<HN; i++)
		{
			partch[l] = i;
			vi nattval = attval;
			for (int j=0; j<HN; j++)
				if (j != i)
					nattval[j] += att[s][j];
			
			exploop(s+1, e, l+1, nattval, partch);
		}
	}
	else if (to_fh)
	{
		int d1 = attval[0] - attval[1];
		int d2 = attval[1] - attval[2];
		int sum = attval[0] + attval[1] + attval[2];
		fh.pb({{d1, d2},  {sum, partch}});
	}
	else
	{
		int d1 = attval[1] - attval[0];
		int d2 = attval[2] - attval[1];
		int sum = attval[0] + attval[1] + attval[2];
		if (sh.count({d1, d2}) == 0 || sh[{d1,d2}].first < sum)
			sh[{d1,d2}] = {sum,partch};
	}
}

vector<char> nomi = {'L', 'M', 'W'};

int main()
{
	ios_base::sync_with_stdio(false);
	int N;
	cin >> N;
	
	for (int i=0; i<N; i++)
		cin >> att[i][0] >> att[i][1] >> att[i][2];
	
	int m = (N+1)/2;
	vi attval(HN);
	vi partch;

    partch.resize(m);
	to_fh = true;
	exploop(0, m-1, 0, attval, partch);
    partch.resize(N-m);
    to_fh = false;
	exploop(m, N-1, 0, attval, partch);
	
	int best_sum = 0;
	vi best_ch;
	bool found = false;
	
	for (auto it : fh)
		if (sh.count(it.first) > 0)
		{
			ch sh_ch = sh[it.first];
			int sum = it.second.first + sh_ch.first;
			if (!found || sum > best_sum)
			{
				found = true;
				best_sum = sum;
				best_ch = it.second.second;
				best_ch.insert(best_ch.end(), sh_ch.second.begin(), sh_ch.second.end());
			}
		}
	

	if (!found)
	{
		cout << "Impossible\n";
		return 0;
	}
	
	for (auto i : best_ch)
	{
		for (int j=0; j<HN; j++)
			if (i != j)
				cout << nomi[j];
		cout << '\n';
	}
}