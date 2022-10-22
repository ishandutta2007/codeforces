#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> v[110];
vector<int> sol;
int memo[110][110];
int distanza(int da,int a){
	if(memo[da][a]>0)return memo[da][a];
  vector<bool> vis(200,0);
  queue<pair<int,int> >q;
  q.push({da,0});
  while(1){
    int pos=q.front().first;
    int d=q.front().second;
    q.pop();
    if(vis[pos])continue;
    vis[pos]=1;
		memo[da][pos]=d;
    if(pos==a)return d;
    for(int i=0;i<v[pos].size();i++)q.push({v[pos][i],d+1});
  }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		int N;
		cin>>N;
		for(int i=0;i<N;i++){
			string a;
			cin>>a;
			for(int j=0;j<N;j++){
				if(a[j]=='1')v[i+1].push_back(j+1);
			}
		}
		int M;
		cin>>M;
		vector<int> giro;
		for(int i=0;i<M;i++){
			int c;
			cin>>c;
			giro.push_back(c);
		}
		sol.push_back(giro[0]);
		int prec=giro[0];
		int dist=2;
		for(int i=1;i<giro.size()-1;i++){
			if(distanza(prec,giro[i+1])==dist){
        dist++;
        continue;
			}
			sol.push_back(giro[i]);
			dist=2;
			prec=giro[i];
		}
		sol.push_back(giro.back());
		cout<<sol.size()<<endl;
		for(int i=0;i<sol.size();i++)cout<<sol[i]<<" ";
		return 0;
}