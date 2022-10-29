#include<iostream>
#include<cstdio>
#include<queue>
#include<set>
using namespace std;
typedef pair<int,int> pii;
set<pii> S;
queue<pii> q;
int T,tot;
bool del[500005];
int main(){
	ios::sync_with_stdio(false);
	int opt,m;
	cin>>T;
	while(T--){
		cin>>opt;
		if(opt==1){
			cin>>m;
			q.push(make_pair(m,++tot));
			S.insert(make_pair(m,-tot));
		}
		else if(opt==2){
			while(del[q.front().second])
				q.pop();
			cout<<q.front().second<<' ';
			del[q.front().second]=1;
			q.pop();
		}
		else{
			while(del[-((--S.end())->second)])
				S.erase(--S.end());
			cout<<-((--S.end())->second)<<' ';
			del[-((--S.end())->second)]=1;
			S.erase(--S.end());
		}
	}
	return 0;
}