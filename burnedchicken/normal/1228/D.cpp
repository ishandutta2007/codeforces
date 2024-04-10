#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
	//ios_base::sync_with_stdio(0),cin.tie(0);
	int n,m,num1,num2,num3,p;
	cin >> n >> m;
	int e[m][2];
	bool t=false;
	bool x[n+1];
	int arr[n+1];
	num1=num2=num3=0;
	for(int i=0; i<m; i++){
		cin >> e[i][0] >> e[i][1];
	}
	for(int i=0; i<(n+1); i++){
		x[i]=false;
		arr[i]=0;
	}
	for(int i=0; i<m; i++){
		if(e[i][0]==1) x[e[i][1]]=true;
		else if(e[i][1]==1) x[e[i][0]]=true;
	}
	for(int i=1; i<(n+1); i++){
		if(not x[i]){
			arr[i]=1;
			num1++;
		}
	}
	for(int i=0; i<m; i++){
		if(e[i][0]==1){
			arr[e[i][1]]=2;
			num2++;
			p=e[i][1];
			break;
		}
		else if(e[i][1]==1){
			arr[e[i][0]]=2;
			num2++;
			p=e[i][0];
			break;
		}
	}
	if(num2==0){
		cout << -1 << endl;
		return 0;
	}
	for(int i=0; i<(n+1); i++){
		x[i]=false;
	}
	for(int i=0; i<m; i++){
		if(e[i][0]==p) x[e[i][1]]=true;
		else if(e[i][1]==p) x[e[i][0]]=true;
	}
	for(int i=1; i<(n+1); i++){
		if(not x[i]){
			if(arr[i]==2) continue;
			if(arr[i]==1){
				cout << -1 << endl;
				return 0;
			}
			arr[i]=2;
			num2++;
		}
	}
	for(int i=1; i<=n; i++){
		if(arr[i]==0){
			arr[i]=3;
			num3++;
		}
	}
	for(int i=0; i<m; i++){
		if(arr[e[i][0]]==arr[e[i][1]]){
			cout << -1 << endl;
			return 0;
		}
	}
	if(num3==0){
		cout << -1 << endl;
		return 0;
	}
	long long int a,b,c;
	a=num1;
	b=num2;
	c=num3;
	if(m==(a*b+b*c+c*a)){
		for(int i=1; i<=n; i++){
			if(arr[i]==1) cout << 1 << " ";
			else if(arr[i]==2) cout << 2 << " ";
			else cout << 3 << " ";
		}
		cout << endl;
	}
	else{
		cout << -1 << endl;
	}
	return 0;
}