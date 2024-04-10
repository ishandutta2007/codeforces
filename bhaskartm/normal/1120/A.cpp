#include<bits/stdc++.h>
using namespace std;
int val[500005];
int val2[500005];
int ans[500005];
int val3[500005];
int main() {
	int m, k, n, s;
	cin>>m>>k>>n>>s;
	int a[m];
	for(int i=0; i<m; i++){
		cin>>a[i];
	}
	int b[s];
	int cnt=0;
	

	for(int i=0; i<s; i++){
		cin>>b[i];
		if(val[b[i]]==0){
			cnt++;
		}
		val[b[i]]++;
	}
	int counter=0;
	int j=0;
	for(int i=0; i<m; i++){
		while(counter<cnt && j<m){
			val2[a[j]]++;
			if(val2[a[j]]==val[a[j]]){
				counter++;
			}
			j++;
		}
		if(counter==cnt){
			ans[i]=j-1;
		}
		else{
			ans[i]=1000000000;
		}
		val2[a[i]]--;
		if(val2[a[i]]+1==val[a[i]]){
			counter--;
		}
	}
	
	int remov=(m-(k*n));
	
	int index=-1;
	for(int i=0; i<m; i++){
		int ahead=(i%k);
		
		if(ahead+(ans[i]-i+1)-remov<=k){
			
			index=i;
			break;
		}
	}
	if(index==-1){
		cout<<-1;
		return 0;
	}
	int ahead=(index%k);
	
	vector<int>v;
	for(int i=0; i<ahead; i++){
		v.push_back(i);
		remov--;
		if(remov==0){
			break;
		}
	}
	for(int i=index; i<m; i++){
		if(remov==0){
			break;
		}
		if(val[a[i]]==val3[a[i]]){
			v.push_back(i);
			remov--;
		}
		else{
			val3[a[i]]++;
		}
	}
	cout<<v.size()<<endl;
	for(auto u:v){
		cout<<u+1<<" ";
	}
	return 0;
}