#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> P;
typedef vector<ll> VI;
typedef vector<VI> VVI;
#define REP(i,n) for(int i=0;i<n;i++)
#define ALL(v) v.begin(),v.end()
constexpr ll MOD=1000000007;
constexpr ll INF=1e18;
 
int main(){
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<string> ss(n);
		REP(i,n) cin >> ss[i];
		vector<vector<bool>> s(n,vector<bool>(m,0));
		REP(i,n)REP(j,m) s[i][j]=ss[i][j]-'0';
		VVI ans(0); int now=0;
		REP(i,n-2){
			REP(j,m-2){
				if(s[i][j]==1){
					ans.push_back({i+1,j+1,i+2,j+1,i+1,j+2});
					s[i][j]=!(s[i][j]);
					s[i+1][j]=!(s[i+1][j]);
					s[i][j+1]=!(s[i][j+1]);
				}
			}
			int c=0; VI an(0);
			if(s[i][m-2]==1){
				c++;
				an.push_back(i+1);
				an.push_back(m-1);
				s[i][m-2]=!(s[i][m-2]);
			}
			if(s[i][m-1]==1){
				c++;
				an.push_back(i+1);
				an.push_back(m);
				s[i][m-1]=!(s[i][m-1]);
			}
			if(c==0)
				continue;
			else{
				REP(j,3-c){
					an.push_back(i+2);
					an.push_back(m-j);
					s[i+1][m-1-j]=!(s[i+1][m-1-j]);
				}
				ans.push_back(an);
			}
		}
		REP(j,m-2){
			int c=0; VI an(0);
			if(s[n-2][j]==1){
				c++;
				an.push_back(n-1);
				an.push_back(j+1);
				s[n-2][j]=!(s[n-2][j]);
			}
			if(s[n-1][j]==1){
				c++;
				an.push_back(n);
				an.push_back(j+1);
				s[n-1][j]=!(s[n-1][j]);
			}
			if(c==0)
				continue;
			else{
				REP(k,3-c){
					an.push_back(n-k);
					an.push_back(j+2);
					s[n-1-k][j+1]=!(s[n-1-k][j+1]);
				}
				ans.push_back(an);
			}
		}
		while(1){
			int c=0; VI an;
			REP(i,2)REP(j,2){
				if(s[n-1-i][m-1-j]==1){
					c++;
					an.push_back(n-i);
					an.push_back(m-j);
				}
			}
			if(c==0)
				break;
			else{
				if(c==2){
					an.pop_back();
					an.pop_back();
					c--;
				}
				if(c==4){
					an.pop_back();
					an.pop_back();
					c--;
				}
				if(c<3){
					REP(i,2){
						REP(j,2){
							if(s[n-1-i][m-1-j]==0){
								c++;
								an.push_back(n-i);
								an.push_back(m-j);
							}
							if(c==3)
								break;
						}
						if(c==3)
							break;
					}
				}
				ans.push_back(an);
				REP(i,3)
					s[an[i*2]-1][an[i*2+1]-1]=!s[an[i*2]-1][an[i*2+1]-1];
			}
		}
		cout << ans.size() << endl;
		REP(i,ans.size()){
			REP(j,6){
				cout << ans[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}