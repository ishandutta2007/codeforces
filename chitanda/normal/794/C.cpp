#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

char s[300100];
int cnta[50], cntb[50];
int n;

int main(){
	scanf("%s", s);
	n = strlen(s);
	sort(s, s + n);
	for(int i = 0; i < (n + 1) / 2; ++i)
		cnta[s[i] - 'a']++;

	scanf("%s", s);
	sort(s, s + n);
	reverse(s, s + n);
	for(int i = 0; i < n / 2; ++i)
		cntb[s[i] - 'a']++;
	
	int l = 1, r = n;
	for(int j = 1; j <= n; ++j){
		int tmin_a = -1, tmin_b = -1, tmax_b = -1, tmax_a = -1;
		for(int i = 0; i < 26; ++i)
			if(cnta[i]) { tmin_a = i; break; }
		for(int i = 25; i >= 0; --i)
			if(cnta[i]) { tmax_a = i; break; }

		for(int i = 0; i < 26; ++i)
			if(cntb[i]) { tmin_b = i; break; }
		for(int i = 25; i >= 0; --i)
			if(cntb[i]) { tmax_b = i; break; }


		if(j & 1){
			if(tmin_a >= tmax_b){
				s[r] = 'a' + tmax_a; cnta[tmax_a]--;
				r--;
			}else{
				s[l] = 'a' + tmin_a; cnta[tmin_a]--;
				l++;
			}
		}else{
			if(tmin_a >= tmax_b){
				s[r] = 'a' + tmin_b; cntb[tmin_b]--;
 				r--;
			}else{
				s[l] = 'a' + tmax_b; cntb[tmax_b]--;
				l++;
			}
		}
	}
	
	for(int i = 1; i <= n; ++i) putchar(s[i]);
	puts("");
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}