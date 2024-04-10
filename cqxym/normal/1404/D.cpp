#include <bits/stdc++.h>
using namespace std;
#define R register int
int main(){
	int n;
	cin>>n;
	if(n%2==0){
		cout<<"First\n";
		for(R k=0;k!=2;k++){
			for(R i=1;i<=n;i++){
				cout<<i<<' ';
			}
		}
		cout<<endl;
	}else{
		cout<<"Second"<<endl;
		vector<int>first(n+1);
		vector<int>oth(n<<1|1);
		for (R i=1;i<=n<<1;i++){
			int a;
			cin>>a;
			if(first[a]>0){
				oth[i]=first[a];
				oth[first[a]]=i;
			}else{
				first[a]=i;
			}
		}
		vector<int>ans;
		vector<bool>visited(n<<1|1);
		for(int i=1;i<=n<<1;i++){
			if(visited[i]==false){
				int cur=i;
				do {
					ans.push_back(cur);
					int nxt=(cur-1+n)%(n<<1)+1;
					visited[cur]=true;
					visited[nxt]=true;
					cur=oth[nxt];
				}while(cur!=i);
			}
		}
		if(accumulate(ans.begin(),ans.end(),0LL)%(n<<1)!=0){
			for(auto i:ans){
				cout<<(i-1+n)%(n<<1)+1<<' ';
			}
		}else{
			for(auto i:ans){
				cout<<i<<' ';
			}
		}
		cout<<endl;
	}
	return 0;
}