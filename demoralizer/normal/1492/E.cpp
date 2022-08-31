#include "bits/stdc++.h"
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=3e5+5;

int diffs[N];

void solve(){
	int n,m;
	cin >> n >> m;
	
	if(m <= 2){
		cout << "Yes\n";
		rep(i,0,m){
			cout << 1 << " ";
		}
		return;
	}
	
	
	vector<vector<int>> a(n+1,vector<int>(m+1));
	
	rep(i,0,n){
		rep(j,0,m){
			cin >> a[i][j];
		}
	}
	
	// diffs from 0
	rep(i,1,n){
		rep(j,0,m){
			if(a[i][j] != a[0][j]){
				diffs[i]++;
			}
		}
	}
	
	int j = 1;
	while(j < n && diffs[j] == 0){
		j++;
	}
	if(j == n){
		cout << "Yes\n";
		rep(i,0,m){
			cout << a[0][i] << " ";
		}
		return;
	}
	
	// 0 and j differ
	
	int pos = 0;
	while(a[0][pos] == a[j][pos]){
		pos++;
	}
	
	// either a[0][pos] is wrong or a[j][pos]
	
	// a[0][pos] is wrong
	rep(hfreiuhf,0,2){
						rep(i,1,n){
							diffs[i] -= (a[0][pos] != a[i][pos]);
						}
						rep(other,0,m){
							if(other == pos){
								continue;
							}
							// 0,pos and 0,other are wrong
							// everything else is right
							int mx = 0;
							rep(i,1,n){
								diffs[i] -= (a[0][other] != a[i][other]);
								amax(mx,diffs[i]);
							}
							
							if(mx <= 2){		
								// diffs contains everything except pos and other
								int z = 1;
								while(z < n && diffs[z] != 2) z++;
								
								if(z < n){
									bool found = 1;
									// a[z][pos] and a[z][other] are both correct
									rep(i,1,n){
										int delta = (a[i][pos] != a[z][pos]);
										delta += (a[i][other] != a[z][other]);
										if(delta + diffs[i] > 2){
											found = 0;
											break;
										}
									}
									if(found){
										cout << "Yes\n";
										rep(i,0,m){
											int x = a[0][i];
											if(i == pos || i == other){
												x = a[z][i];
											}
											cout << x << " ";
										}
										return;
									}
								}
								else{
									z = 1;
									while(z < n && diffs[z] != 1) z++;
									if(z < n){
										// a[z][pos] or a[z][other] is correct
										int k = pos;
										
										rep(zzzzzz,0,2){
											int omx = 0;
											rep(i,1,n){
												if(a[i][k] != a[z][k]) diffs[i]++;
												amax(omx,diffs[i]);
											}
											
											if(omx <= 2){
												bool found = 1;
												int zz = 1;
												while(zz < n){
													if(zz != z && diffs[zz] == 2){
														break;
													}
													zz++;
												}
												if(zz < n){
													int l = pos ^ other ^ k;
													
													// a[z][k] is correct, a[zz][l] is correct
													rep(i,1,n){
														if(i == z) continue;
														int delta = (a[i][l] != a[zz][l]);
														if(delta + diffs[i] > 2){
															found = 0;
															break;
														}
													}
													if(found){
														cout << "Yes\n";
														rep(i,0,m){
															int x = a[0][i];
															if(i == k){
																x = a[z][i];
															}
															if(i == l){
																x = a[zz][i];
															}
															cout << x << " ";
														}
														return;
													}
												}
												else{
													cout << "Yes\n";
													// cout << pos << " " << other << " " << j << " " << z << " " << zz << "\n";
													rep(i,0,m){
														int x = a[0][i];
														if(i == pos || i == other){
															x = a[z][i];
														}
														cout << x << " ";
													}
													return;
												}
											}
											
											rep(i,1,n){
												if(a[i][k] != a[z][k]) diffs[i]--;
											}
											k = other;
										}
										
										
									}
									else{
										// all can be changed twice
										cout << "Yes\n";
										rep(i,0,m){
											cout << a[0][i] << " ";
										}
										return;
									}
								}
							}
							rep(i,1,n){
								diffs[i] += (a[0][other] != a[i][other]);
							}
						}
		rep(i,0,n){
			diffs[i] = 0;
		}
		rep(zcz,0,m){
			swap(a[0][zcz],a[j][zcz]);
		}
		rep(i,1,n){
			rep(j,0,m){
				if(a[i][j] != a[0][j]){
					diffs[i]++;
				}
			}
		}
	}
	// rep(i,0,n){
	// 	diffs[i] = 0;
	// }
	
	// print no if not found
	cout << "No";
	
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}