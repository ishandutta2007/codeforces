/*
   yorokobi mo kanashimi mo wakeaeba tsuyomaru omoi
   kono koe ga todoku no nara
   kitto kiseki ha okoseru darou..
*/

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int n, k, tt[MAXN], gg[MAXN], nd[MAXN];
bool mark[MAXN], vis[MAXN];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	while (te--){
		cin >> n >> k;
		for (int i = 0; i < k; i++)	cin >> tt[i], gg[i] = tt[i], mark[i] = 0, vis[i] = 0, nd[i] = 0;

		bool done = 0;
		int cn = 0, cn2 = 1e8;
		for (int i = 0; i < n - 1; i++){
			int x;	bool t;	cin >> x >> t;

			if (!done && t){
				done = 1;
				for (int j = 0; j < k; j++)
					if (gg[j] - cn <= 0)	mark[j] = 1, nd[j] = gg[j];
			}

			if (x){
				gg[--x]--;
				if (done)
					vis[x] = 1;
			}
			else cn++;
		}

		for (int i = 0; i < k; i++)
			if (mark[i] && !vis[i])	cn2 = min(cn2, nd[i]);

		for (int i = 0; i < k; i++)
			if (!done){
				if (gg[i] - cn <= 0)	
					cout << "Y";
				else
					cout << "N";
			}
			else{
				if ((mark[i] && !vis[i]) || gg[i] - (cn - cn2) <= 0)
					cout << "Y";
				else
					cout << "N";
			}
		cout << "\n";
	}	
	return	0;
}