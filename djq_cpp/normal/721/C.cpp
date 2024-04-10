/****************************************************************************************************
 * author:                                                                                          *
 *                                                                                                  *
 *            #        ###                                                                          *
 *            #        ###                                                                          *
 *            #                                                                                     *
 *            #         #                                                                           *
 *    ####### #         #       ####### #               #######      # #######      # #######       *
 *   ##      ##         #      ##      ##             ##       ##    ##      ##     ##      ##      *
 *   #        #         #      #        #             #              #        #     #        #      *
 *   ##      ##         #      ##      ##             ##       ##    ##      ##     ##      ##      *
 *    ####### #         #       ####### #    #######    #######      # #######      # #######       *
 *                      #               #                            #              #               *
 *                  #   #               #                            #              #               *
 *                   ###                #                            #              #               *
 *                                      #                            #              #               *
 *                                      #                            #              #               *
 *                                                                                                  *
 ****************************************************************************************************
 * contest:                                                                                         *
 * Codeforces Round #___(Div._)                                                                     *
 ****************************************************************************************************
 */
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
vector<pii> adj[5005];
vector<int> Ts;
int dp[5005][5005],prev[5005][5005],deg[5005];
int main(){
	int n,m,x,y,t,T;
	scanf("%d%d%d",&n,&m,&T);
	rep(k,m){
		scanf("%d%d%d",&x,&y,&t);
		adj[x].push_back(MP(y,t));
		deg[y]++;
	}
	queue<int> que;
	rep1(k,n)if(deg[k]==0)que.push(k);
	while(!que.empty()){
		int out=que.front();
		que.pop();
		Ts.push_back(out);
		rep(k,adj[out].size()){
			int v=adj[out][k].first;
			deg[v]--;
			if(deg[v]==0)que.push(v);
		}
	}
	rep(i,5005)rep(j,5005)dp[i][j]=INF;
	dp[1][1]=0;
	prev[1][1]=-1;
	rep(i,Ts.size()){
		int v=Ts[i];
		rep(j,adj[v].size()){
			int newv=adj[v][j].first;
			rep1(k,i+1)
			if(dp[newv][k+1]>dp[v][k]+adj[v][j].second){
				dp[newv][k+1]=dp[v][k]+adj[v][j].second;
				prev[newv][k+1]=v;
			}
		}
	}
	int ans=n,id=n;
	vector<int> res;
	while(dp[n][ans]>T&&ans>=0)ans--;
	printf("%d\n",ans);
	while(id!=-1){
		res.push_back(id);
		id=prev[id][ans];
		ans--;
	}
	reverse(res.begin(),res.end());
	rep(k,res.size())printf("%d ",res[k]);
	return 0;
}