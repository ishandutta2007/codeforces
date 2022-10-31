#include <bits/stdc++.h>
 
using namespace std;
 
vector <int> cn [1010];
int N,k,bt [110][110], vis[110][110],anw[110][110],A[110];
int dp (int id, int prev)
{
	if (id == N) return 1;
	if(vis[id][prev] == k) return anw[id][prev];
	if (A[id] != -1) return A[id] == prev ? 0 : dp(id+1,A[id]);
	for (int &i : cn[id])
	{
		if (i == prev) continue;
		if (dp (id+1,i))
		{
			vis[id][prev] = k;
			bt[id][prev] = i;
			return anw[id][prev] = 1;
		}
	}
	vis[id][prev] = k;
	return anw[id][prev] = 0;
}
 
bool rv (char x)
{
	if (x >= '0' && x <= '9') return 0;
	if (x >= 'a' && x <= 'z') return 0;
	if (x >= 'A' && x <= 'Z') return 0;
	return 1;
}
 
int main ()
{
	int T;
	cin >> T;
	
	while (T--)
	{
		k++;
		int n;
		cin >> n;
		
		vector <string> NM (n);
		for (string &s : NM) cin >> s;
		map <string,int> sid;
		int ii = 0;
		for (string &s : NM) sid[s] = ii++;
		
		int m;
		cin >> m;
		N = m;
		vector <string> MS (m);
		getline(cin,MS[0]);
		for (int i = 0; i < m; i++)
		{
			getline(cin,MS[i]);
			int p = MS[i].find(":");
			string a = MS[i].substr(0,p);
			MS[i] = MS[i].substr(p);
			MS[i] += " ";
			cn[i].clear();
			if (a == "?")
			{
				A[i] = -1;
				set <int> ag;
				for (int dd = 0; dd < n; dd++) ag.insert(dd);
				for (int j = 0; j < n; j++)
				{
					int p = MS[i].find(NM[j]);
					while (p != -1)
					{
						if (rv(MS[i][p-1]) && rv(MS[i][p+NM[j].size()]))
						{
							ag.erase(j);
							break;
						}
						p = MS[i].find(NM[j],p+NM[j].size());
					}
				}
				for (int dd : ag) cn[i].push_back(dd);
			}
			else A[i] = sid[a];
		}
		
		if (!dp(0,n)) puts("Impossible");
		else
		{
			int p = n;
			for (int i = 0; i < m; i++)
			{
				MS[i].pop_back();
				if (A[i] != -1)
				{
					cout << NM[A[i]] << MS[i] << endl;
					p = A[i];
				}
				else
				{
					cout << NM[bt[i][p]] << MS[i] << endl;
					p = bt[i][p];
				}
			}
		}
	}
}