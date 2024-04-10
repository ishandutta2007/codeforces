#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxm=555;

int n,m;
int cnt[maxm],pfx[maxm];
vector<pair<int,int> > v[maxm];
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int f,g=0;cin>>f;
		while(f--){
			int s;cin>>s;g|=(1<<(s-1));
		}
		cnt[g]++;
	}	
	for(int i=0;i<(1<<9);i++){
		pfx[i]=cnt[0];
		for(int j=i;j;j=(j-1)&i)pfx[i]+=cnt[j];
	}
	for(int i=1;i<=m;i++){
		int f,c,g=0;cin>>c>>f;
		while(f--){
			int s;cin>>s;g|=(1<<(s-1));
		}
		v[g].push_back(make_pair(c,i)); 
	}
	for(int i=0;i<(1<<9);i++){
		sort(v[i].begin(),v[i].end());
	}
	int mxs=-1,mic=0,id1=0,id2=0;
	for(int i=0;i<(1<<9);i++){
		if(v[i].size()>=2){
			int gt=pfx[i],cs=v[i][0].first+v[i][1].first;
			if(gt>mxs||(gt==mxs&&cs<mic)){
				mxs=gt;mic=cs;
				id1=v[i][0].second;id2=v[i][1].second;
			}
		}
	}
	for(int i=0;i<(1<<9);i++){
		for(int j=i+1;j<(1<<9);j++){
			if(v[i].size()>=1&&v[j].size()>=1){
				int gt=pfx[i|j],cs=v[i][0].first+v[j][0].first;
				if(gt>mxs||(gt==mxs&&cs<mic)){
					mxs=gt;mic=cs;
					id1=v[i][0].second;id2=v[j][0].second;
				}
			}
		} 
	}
	cout<<id1<<' '<<id2;
	return 0;
}