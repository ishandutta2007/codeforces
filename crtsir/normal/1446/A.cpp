#include<bits/stdc++.h>
using namespace std;
long long T,n,W,w[200003],idx[200003];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>W;
		int ONE=-1;
		vector<pair<int,int> >V;
		for(int i=0;i<n;i++){
			scanf("%lld",w+i);
			if(w[i]<=W){
				if(w[i]>=(W+1)/2)
					ONE=i;
				else
					V.push_back(make_pair(w[i],i));
			}
		}
		if(ONE!=-1){
			cout<<"1\n"<<1+ONE<<endl;
			continue;
		}
		long long cnt=0;
		for(int i=0;i<V.size();i++)
			cnt+=V[i].first;
		if(cnt<(W+1)/2){
			cout<<-1<<endl;
			continue;
		}
		for(int i=V.size()-1;i>=0;i--)
			if(cnt>W){
				cnt-=V[i].first;
				V.pop_back();
			}
		cout<<V.size()<<endl;
		for(int i=0;i<V.size();i++)
			printf("%d ",V[i].second+1);
		cout<<endl;
	}
}