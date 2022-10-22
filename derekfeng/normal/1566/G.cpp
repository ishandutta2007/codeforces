#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class T>
T rand(T a,T b){
	return uniform_int_distribution<T>(a,b)(rng);
}
const int c=100005,k=110,sok=2e9;
int n,m,q;
bool t[c][k];
map<pair<int,int>,int>el;
multiset<int>s1[c];
priority_queue<int,vector<int>,greater<int> >aa[k][2],bb[k][2];
multiset<long long>r;
long long res(int a){
	long long ans=0;
	int cnt=0;
	for(auto x:s1[a]){
		ans+=x;
		cnt++;
		if(cnt==3){
			return ans;
		}
	}
}
void valt(int id){
	int a,b,suly;
	cin>>a>>b;
	if(a>b){
		swap(a,b);
	}
	if(id){
		cin>>el[{a,b}];
	}
	suly=el[{a,b}];
	if(!id){
		el.erase({a,b});
	}
	r.erase(r.find(res(a))),r.erase(r.find(res(b)));
	if(id){
		s1[a].insert(suly),s1[b].insert(suly);
	}else{
		s1[a].erase(s1[a].find(suly)),s1[b].erase(s1[b].find(suly));
	}
	r.insert(res(a)),r.insert(res(b));
	for(int i=0;i<k;i++){
		if(t[a][i]==t[b][i]){
			int h=t[a][i];
			if(id){
				aa[i][h].push(suly);
			}else{
				bb[i][h].push(suly);
			}
		}
	}
}
void calc(){
	long long mini=*(r.begin());
	for(int i=0;i<k;i++){
		long long sum=0;
		for(int j=0;j<2;j++){
			while(aa[i][j].top()==bb[i][j].top()){
				aa[i][j].pop(),bb[i][j].pop();
			}
			sum+=aa[i][j].top();
		}
		mini=min(mini,sum);
	}
	cout<<mini<<"\n";
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			s1[i].insert(sok);
		}
		r.insert(res(i));
	}
	for(int j=0;j<k;j++){
		for(int i=1;i<=n;i++){
			t[i][j]=rand(0,1);
		}
		aa[j][0].push(sok),aa[j][1].push(sok);
		bb[j][0].push(sok+1),bb[j][1].push(sok+1);
	}
	for(int i=1;i<=m;i++){
		valt(1);
	}
	calc();
	cin>>q;
	for(int i=1;i<=q;i++){
		int id;
		cin>>id;
		valt(id);
		calc();
	}
	return 0;
}