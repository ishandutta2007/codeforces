#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<pair<pair<int,int> ,int> > p;
int controlla(int a,int b,int c,int d){
	vector<pair<int,int> > l;
	l.push_back({p[a].second,a});
	l.push_back({p[b].second,b});
	l.push_back({p[c].second,c});
	l.push_back({p[d].second,d});
	sort(l.begin(),l.end());
	if(l[0].first==l[1].first && l[1].first!=l[2].first && l[2].first==l[3].first){
		int a1=l[0].second,a2=l[1].second,b1=l[2].second,b2=l[3].second;
		int diffa=abs(p[a1].first.second-p[a2].first.second)%2;
		int diffb=abs(p[b1].first.second-p[b2].first.second)%2;
		if(diffa+diffb==1)return 0;
	}
	return p[a].first.first+p[b].first.first+p[c].first.first+p[d].first.first;
}
int main(){
		ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
		int T;
		cin>>T;
		while(T--){
			while(p.size())p.erase(p.begin()+p.size()-1);
			int N,M;
			cin>>N>>M;
			if(N<4){
				vector<int>zz;
				for(int i=0;i<N;i++){
					for(int j=0;j<M;j++){
						int a;
						cin>>a;
						zz.push_back(a);
					}
				}
				sort(zz.begin(),zz.end(),greater<int> ());
				int tot=0;
				for(int i=0;i<N;i++)tot+=zz[i];
				cout<<tot<<'\n';
			}else{
				for(int i=0;i<N;i++){
					for(int j=0;j<M;j++){
						int a;
						cin>>a;
						p.push_back({{a,i},j});
					}
				}
				sort(p.begin(),p.end(),greater<pair<pair<int,int>,int> >());
				int tot=0;
				int limit=min(8,N*M);
				for(int i=0;i<limit;i++){
					for(int j=i+1;j<limit;j++){
						for(int h=j+1;h<limit;h++){
							for(int q=h+1;q<limit;q++){
								tot=max(tot,controlla(i,j,h,q));
							}
						}
					}
				}
				cout<<tot<<endl;
			}
		}
		return 0;
}