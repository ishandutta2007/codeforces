#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}
template<typename T>
void prl(T a){cout<<a<<"\n";}
template<typename T,typename... Args>
void prl(T a, Args... args) {cout<<a<<" ",prl(args...);}
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
int yc[7]={0,0,1,1,0,0,1};
int xc[7]={0,100,0,0,1,-1,0};
vector<int> side={4,5};
vector<int> up={3};
vector<int> down={6};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int q;
	sc(q);
	while(q--){
		int n;
		sc(n);
		int arr[2][n];
		string a;
		sc(a);
		rep(i,0,n){
			arr[0][i]=a[i]-'0';
			if(arr[0][i]==1||arr[0][i]==2){
				arr[0][i]=0;
			}
			else arr[0][i]=1;
		}
		sc(a);
		rep(i,0,n){
			arr[1][i]=a[i]-'0';
			if(arr[1][i]==1||arr[1][i]==2){
				arr[1][i]=0;
			}
			else arr[1][i]=1;
		}
		queue<pair<pii,int>> q;
		bool poss[2][n][7];
		memset(poss,false,sizeof(poss));
		if(arr[0][0]==0){
			q.push({{0,0},2});
			poss[0][0][2]=true;
		}
		else if(arr[0][0]==1){
			q.push({{0,0},4});
			poss[0][0][4]=true;
		}
		while(q.size()){
			auto cur=q.front();
			q.pop();
			pii next={xc[cur.second]+cur.first.first,yc[cur.second]+cur.first.second};
			if(next.second<n&&next.first>=0&&next.first<2){
				if(arr[next.first][next.second]==1) {
					if (yc[cur.second]) {
						for (int x:side) {
							if (!poss[next.first][next.second][x]) {
								poss[next.first][next.second][x] = true;
								q.push({next, x});
							}
						}
					} else if (xc[cur.second] == 1) {
						for (int x:down) {
							if (!poss[next.first][next.second][x]) {
								poss[next.first][next.second][x] = true;
								q.push({next, x});
							}
						}
					} else {
						for (int x:up) {
							if (!poss[next.first][next.second][x]) {
								poss[next.first][next.second][x] = true;
								q.push({next, x});
							}
						}
					}
				}
				else{
					if(yc[cur.second]){
						if (!poss[next.first][next.second][2]) {
							poss[next.first][next.second][2] = true;
							q.push({next, 2});
						}
					}
				}
			}
		}
		if(poss[1][n-1][6]||poss[1][n-1][2]){
			prl("YES");
		}
		else prl("NO");
	}
    return 0;
}