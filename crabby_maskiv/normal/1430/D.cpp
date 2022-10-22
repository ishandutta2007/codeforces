#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
int n,m;
char a[N];
queue<int> q1;
queue<pair<int,int> > q2;
bool del[N];
int main(){
	int i,j;
	int T;cin>>T;
	while(T--){
		cin>>n;
		cin>>(a+1);
		int sum=0;
		for(i=1;i<=n;i++){
			sum++;
			if(a[i]!=a[i+1]){
				if(sum>1) q2.push({sum-1,i});
				q1.push(i);
				sum=0;
			}
		}
		int ans=0;
		while(!q1.empty()){
			ans++;
			if(q2.empty()){
				q1.pop();
				if(!q1.empty()) q1.pop();
			}
			else{
				q2.front().first--;
				if(q2.front().first==0) q2.pop();
				if(!q2.empty()&&q2.front().second==q1.front()){
				//	cout<<"OK"<<endl;
					q2.pop();
				}
				q1.pop();
			}
		}
		cout<<ans<<endl;
		for(i=1;i<=n;i++) a[i]=0;
	}
	return 0;
}