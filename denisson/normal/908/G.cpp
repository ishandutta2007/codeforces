#include <bits/stdc++.h>
                      
using namespace std;
              
typedef long long ll;
#define mp make_pair
#define pub push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db double

const int mod = (int)1e9 + 7;

void add(int &a, int b){
	a += b;
	if (a >= mod) a -= mod;
}
  
int mult(int a, int b){
	return a * (ll)b % mod;
}

int sum(int a, int b){
	int ans = a + b;
	if (ans >= mod) ans -= mod;
	return ans;
}

int dp[701][701][2];
int cnt[701][701][2];
int step[777];

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
   	string s;
   	cin >> s;
	   	
   	int ans = 0;

   	step[0] = 1;
   	for (int i = 1; i < 777; i++) step[i] = mult(step[i - 1], 10);

   	for (int c = 1; c <= 9; c++){

   		for (int s1 = 0; s1 < 701; s1++) for (int s2 = 0; s2 < 701; s2++) for (int s3 = 0; s3 < 2; s3++) dp[s1][s2][s3] = cnt[s1][s2][s3] = 0;

   		cnt[0][0][0] = 1;
   		for (int i = 0; i < s.size(); i++){
   			for (int was = 0; was <= i; was++) for (int f = 0; f < 2; f++){
   				int ma = 9;
   				if (f == 0) ma = s[i] - '0';
   				for (int cc = 0; cc <= ma; cc++){
   					int ww = was + (cc >= c);
   					int ff = max(f, (int)(cc < s[i] - '0'));
   					if (cc == c){
   						add(dp[i + 1][ww][ff], sum(dp[i][was][f], mult(cnt[i][was][f], mult(c, step[was]))));
   					} else if (cc > c){
   						add(dp[i + 1][ww][ff], mult(dp[i][was][f], 10));
   					} else {	
   						add(dp[i + 1][ww][ff], dp[i][was][f]);
   					}
   					add(cnt[i + 1][ww][ff], cnt[i][was][f]);
   				}
   			}
   		}

   		for (int was = 0; was <= s.size(); was++) for (int f = 0; f < 2; f++) add(ans, dp[s.size()][was][f]);
   	}
   	cout << ans;
}