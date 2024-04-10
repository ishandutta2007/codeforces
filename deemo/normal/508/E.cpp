/*
   kawashita yakusoku wasurenai yo
   me wo tojitashikameru
   oshiyoseta yami furiharatte susumu yo
   donna ni ookina kabe ga attemo
   koetemiseru kara kitto
   ashita shinjite inotte	
 */

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

#define I_FAILED {cout << "IMPOSSIBLE\n";	return 0;}

const int MAXN = 600 + 20;

int n;
int l[MAXN], r[MAXN];
string ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)	cin >> l[i] >> r[i];
	if (l[n - 1] > 1)	I_FAILED
	ans = "()";

	for (int i = n - 2; i >= 0; i--){
		int tl = l[i], tr = r[i];
		if (tl == 1){
			ans = "()" + ans;
			continue;
		}

		bool SHE_LIKES_ME = 0;
		int cc = 0;
		for (int j = 0; !SHE_LIKES_ME && j < (int)ans.size(); j++){
			if (ans[j] == '(')	cc++;
			else	cc--;
			
			if (cc == 0 && tl <= j + 2 && j + 2 <= tr)
				SHE_LIKES_ME = 1, ans = '(' + ans, ans.insert(ans.begin() + j + 2, ')');
		}

		if (!SHE_LIKES_ME)	I_FAILED//:P
	}

	cout << ans << "\n";
	return	0;
}