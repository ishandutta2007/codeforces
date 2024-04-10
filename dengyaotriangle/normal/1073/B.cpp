#include<bits/stdc++.h>

using namespace std;

const int maxn=200005;

bool vis[maxn];
int k[maxn];
int n;
stack<int> s;

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>k[i];
	for(int i=n-1;i>=0;i--) s.push(k[i]);
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		int cnt=0;
		if(!vis[tmp]){
			while(1){
				int c=s.top();s.pop();
				cnt++;
				vis[c]=1;
				if(c==tmp) break;
			}
		}
		cout<<cnt<<' ';
	}
	return 0;
}