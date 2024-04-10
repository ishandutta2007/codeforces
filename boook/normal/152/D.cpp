/*input
4 5
#####
#.#.#
###.#
#####
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB44(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 1010
#define INF 0x3f3f3f3f

vector<string> v , vv;
int n , m , nn , mm , nox[MAX] , noy[MAX];
string s;
void DB4(int a , int b , int c , int d){
	a ++ , b ++ , c ++ , d ++;
	int cnt;
	cnt = 0;
	REP(i , 0 , n){
		if(nox[i] == 0){
			cnt ++;
			if(cnt == a){
				while(nox[i + 1]) i ++;
				a = i;
				break;
			}
		}
	}
	cnt = 0;
	REP(i , 0 , n){
		if(nox[i] == 0){
			cnt ++;
			if(cnt == c){
				while(nox[i + 1]) i ++;
				c = i;
				break;
			}
		}
	}
	cnt = 0;
	REP(i , 0 , m){
		if(noy[i] == 0){
			cnt ++;
			if(cnt == b){
				while(noy[i + 1]) i ++;
				b = i;
				break;
			}
		}
	}
	cnt = 0;
	REP(i , 0 , m){
		if(noy[i] == 0){
			cnt ++;
			if(cnt == d){
				while(noy[i + 1]) i ++;
				d = i;
				break;
			}
		}
	}
	cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << endl;
}
void solveinit1(){
	REP(i , 0 , n){
		cin >> s;
		if(v.size() >= 5 && s == v.back() && s == v[v.size() - 2] 
			&& s == v[v.size() - 3] && s == v[v.size() - 4]
			&& s == v[v.size() - 5]) nox[i] = 1;
		else v.pb(s);
	}
	REP(j , 0 , m){
		string s;
		REP(i , 0 , v.size()) s += v[i][j];
		if(vv.size() >= 5 && s == vv.back() && s == vv[vv.size() - 2]
			&& s == vv[vv.size() - 3] && s == vv[vv.size() - 4]
			&& s == vv[vv.size() - 5]) noy[j] = 1;
		else vv.pb(s);
	}
	REP(i , 0 , v.size()){
		string tmp;
		REP(j , 0 , m){
			if(noy[j]) continue;
			tmp += v[i][j];
		}
		v[i] = tmp;
	}
}
int check(int a , int b , int c , int d){
	
	REP(i , a , c + 1) if(v[i][b] == '.' || v[i][d] == '.') return 0;
	REP(i , b , d + 1) if(v[a][i] == '.' || v[c][i] == '.') return 0;
	return 1;
}
int check(int a , int b , int c , int d , int aa , int bb , int cc , int dd){
	REP(i , aa , cc + 1) if(v[i][bb] == '.' || v[i][dd] == '.') return 0;
	REP(i , bb , dd + 1) if(v[aa][i] == '.' || v[cc][i] == '.') return 0;
	REP(i , a , c + 1) if(v[i][b] == '.' || v[i][d] == '.') return 0;
	REP(i , b , d + 1) if(v[a][i] == '.' || v[c][i] == '.') return 0;

	vv = v;
	REP(i , a , c + 1) vv[i][b] = vv[i][d] = '?';
	REP(i , b , d + 1) vv[a][i] = vv[c][i] = '?';
	REP(i , aa , cc + 1) vv[i][bb] = vv[i][dd] = '?';
	REP(i , bb , dd + 1) vv[aa][i] = vv[cc][i] = '?';
	REP(i , 0 , nn) REP(j , 0 , mm) if(vv[i][j] == '#') return 0;
	return 1;
}
int X[] = {-1 , 0 , 0 , 1};
int Y[] = {0 , 1 , -1 , 0};
int32_t main(){
	IOS , cin >> n >> m;
	solveinit1();
	nn = v.size() , mm = v[0].size();
	REP(i , 0 , nn) REP(j , 0 , mm) if(v[i][j] == '#'){
		int cnt = 0;
		REP(k , 0 , 4){
			int tox = i + X[k] , toy = j + Y[k];
			if(0 <= tox && tox < nn && 0 <= toy && toy <= mm){
				// DB44("tox = " , tox , "toy = " , toy);
				if(v[tox][toy] == '#') cnt ++;
			}
		}
		// if(cnt < 2) DBGG(i , j);
		if(cnt < 2) return cout << "NO" << endl , 0;
	}
	// REP(i , 0 , nn) cout << v[i] << endl;
	// REP(i , 0 , n) cout << nox[i] << " " ; cout << endl;
	// REP(i , 0 , m) cout << noy[i] << " " ; cout << endl;
	int cnt = 0;
	REP(aa , 0 , nn){
		REP(bb , 0 , mm){
			REP(cc , aa + 2 , nn){
				REP(dd , bb + 2 , mm){
					if(check(aa , bb , cc , dd) == 0) continue;
					REP(i , 0 , nn){
						REP(j , 0 , mm){
							REP(ii , i + 2 , nn){
								REP(jj , j + 2 , mm){
									if(check(aa , bb , cc , dd , i , j , ii , jj)){
										cout << "YES" << endl;
										DB4(aa , bb , cc , dd);
										DB4(i , j , ii , jj);
										return 0;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "NO" << endl;
	// DBGG("cnt = " , cnt);
    return 0;
}