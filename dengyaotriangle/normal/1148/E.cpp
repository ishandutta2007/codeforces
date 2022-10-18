#include<bits/stdc++.h>

using namespace std;

const int maxn=300005;

int d[maxn];
int n;
pair<int,int> sp[maxn];
int ep[maxn];

stack<pair<int,int> > stk;
vector<pair<pair<int,int>,int> > v;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n; 
	for(int i=1;i<=n;i++) cin>>sp[i].first;
	for(int i=1;i<=n;i++) sp[i].second=i;
	for(int i=1;i<=n;i++) cin>>ep[i];
	sort(sp+1,sp+1+n);
	sort(ep+1,ep+1+n); 
	for(int i=1;i<=n;i++)d[i]=ep[i]-sp[i].first;
	for(int i=1;i<=n;i++){
		if(d[i]>0){
			stk.push(make_pair(d[i],sp[i].second));
		}else{
			d[i]=-d[i]; 
			while(d[i]!=0){
				if(stk.empty()){
					cout<<"NO";
					return 0;
				}
				int dl=stk.top().first,id=stk.top().second;stk.pop();
				if(dl<=d[i]){
					d[i]-=dl;
					v.push_back(make_pair(make_pair(id,sp[i].second),dl));
				}else{
					v.push_back(make_pair(make_pair(id,sp[i].second),d[i]));
					dl-=d[i];
					d[i]=0;	
					stk.push(make_pair(dl,id)); 
				}
			}
		}
	}	 
	if(!stk.empty()){
		cout<<"NO";
		return 0;
	} 
	cout<<"YES\n"<<v.size()<<'\n';
	for(int i=0;i<v.size();i++){
		cout<<v[i].first.first<<' '<<v[i].first.second<<' '<<v[i].second<<'\n';
	}
	return 0;
}