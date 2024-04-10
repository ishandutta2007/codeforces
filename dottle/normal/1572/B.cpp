#include<bits/stdc++.h>
const int N=2000500;
using namespace std;

int pr[2],f[N],n,t,a[N],s[N];
queue<int> q;

void out(int l,int r){
	for(int i=r-2;i>=l;i-=2)q.push(i);
	for(int i=l;i<r;i+=2)q.push(i);
}

int main(){
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i],s[i]=a[i]^s[i-1];
		if(!s[n]){
			if(n&1)out(1,n);
			else{
				for(int i=1;i<=n;i+=2){
					if(s[i]==0){
						out(1,i);
						out(i+1,n);
						break;
					}
				}
			}
		}
		if(q.size())cout<<"YES"<<endl<<q.size()<<endl;
		else cout<<"NO";
		while(q.size())cout<<q.front()<<' ',q.pop();
		cout<<endl;
	}
}