#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

#define up asdkfljasdf

const int MAXN = 1e6 + 10;

int n, up, dn;
string s;
ll p_dn[MAXN], p_up[MAXN];
int vec[MAXN], sz, sec[MAXN], sz2;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		p_up[i + 1] = p_up[i] + (s[i] == 'U'?i+1:0)
			, p_dn[i + 1] = p_dn[i] + (s[i] == 'D'?n - i:0);
		if (s[i] == 'U')
			vec[sz++] = i;
		else
			sec[sz2++] = i;
	}
	
	for (int i = 0; i < n; i++){
		int cu = upper_bound(vec, vec + sz, i) - vec, cd = (sec + sz2) - lower_bound(sec, sec + sz2, i);
		ll ret = 0;
		
		if (s[i] == 'U'){
			if (cu > cd){
				int temp = cu;
				cu = cd+1;
				ret = 1ll * (cu + cd) * (n - i) - ((p_dn[n] - p_dn[i]) << 1);
				ret += 2ll * cd * (i + 1) - ((p_up[i] - p_up[vec[temp - cu]])<< 1);
			}
			else{
				int temp = sz2 - cd;
				cd = cu;
				ret = 1ll * (2 * cd - 1) * (i + 1) - ((p_up[i]) << 1);
				ret += 1ll * (cu + cd) * (n - i) - ((p_dn[sec[temp + cd-1]+1] - (temp?p_dn[sec[temp-1] + 1]:0)) << 1);
			}
		}
		else{
			if (cd > cu){
				int temp = sz2 - cd + 1;
				cd = cu+1;
				ret = 1ll * (cu+cd) * (i + 1) - ((p_up[i]) << 1);
				ret += 1ll * (cu + cd-1) * (n - i) - ((p_dn[sec[temp + cd-2]+1] - (p_dn[i+1])) << 1);
			}
			else{
				int temp = cu;
				cu = cd;
				ret = 1ll * (cu + cd - 1) * (n - i) - ((p_dn[n] - p_dn[i+1]) << 1);
				ret += 2ll * cd * (i + 1) - ((p_up[i] - p_up[vec[temp - cu]])<< 1);
			}
		}

		cout << ret << " ";
	}
	cout << "\n";
	return 0;
}