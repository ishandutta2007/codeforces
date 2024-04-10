/*




D P 




 l l
*/
#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
const int N=1000;
int n;
set<int> nei[N+1];
vector<int> v; 
void dfs(int x,int fa=0){
	v.pb(x);
	for(set<int>::iterator i=nei[x].begin();i!=nei[x].end();i++)if(*i!=fa)dfs(*i,x);
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		nei[x].insert(y);nei[y].insert(x);
	}
	int now=1;
	while(true){
		v.clear();dfs(now);
		bool ok=false;
		for(int i=0;i<v.size();i++)if(nei[v[i]].size()>1){
			ok=true;
			int a=*nei[v[i]].begin(),b=*++nei[v[i]].begin();
			cout<<"? "<<a<<" "<<b<<"\n";
			int c;
			cin>>c;
			if(c==a)now=a,nei[a].erase(v[i]);
			else if(c==b)now=b,nei[b].erase(v[i]);
			else now=c,nei[c].erase(a),nei[c].erase(b);
			break;
		}
		if(!ok){
			if(nei[now].size()==0)cout<<"! "<<now<<"\n";
			else{
				cout<<"? "<<now<<" "<<*nei[now].begin()<<"\n";
				int a;
				cin>>a;
				cout<<"! "<<a<<"\n";
			}
			return 0;
		}
	}
	return 0;
}