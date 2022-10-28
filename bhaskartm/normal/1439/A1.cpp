#include <bits/stdc++.h>
using namespace std;
#pragma optimize("-O3")
#define int long long int
#define f first
#define s second
#define pb push_back
#define endl '\n'
int n, m;
vector<pair<int, int>>ans;
int arr[105][105];

void f2(int i, int j){
	arr[i][j]=1-arr[i][j];
}

void f(int i, int j){
	int val=0;
	for(int k=i; k<=i+1; k++){
		for(int k2=j; k2<=j+1; k2++){
			val+=arr[k][k2];
		}
	}
	
	if(val==0){
		return;
	}
	if(val==3){
		if(arr[i][j]==0){
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
		}
		if(arr[i+1][j]==0){
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
		}
		if(arr[i][j+1]==0){
			
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
		}
		if(arr[i+1][j+1]==0){
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
		}
		return;
	}
	if(val==4){
		ans.pb({i+1, j+1});
		ans.pb({i+1, j});
		ans.pb({i, j+1});
		ans.pb({i+1, j+1});
		ans.pb({i, j});
		ans.pb({i, j+1});
		ans.pb({i+1, j+1});
		ans.pb({i, j});
		ans.pb({i+1, j});
		ans.pb({i, j+1});
		ans.pb({i, j});
		ans.pb({i+1, j});
		return;
	}
	if(val==2){
		if(arr[i][j]==1 && arr[i+1][j]==1){
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
		}
		if(arr[i][j]==1 && arr[i][j+1]==1){
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
		}
		if(arr[i+1][j+1]==1 && arr[i+1][j]==1){
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
		}
		if(arr[i+1][j+1]==1 && arr[i][j+1]==1){
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
		}
		if(arr[i][j]==1 && arr[i+1][j+1]==1){
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
		}
		if(arr[i][j+1]==1 && arr[i+1][j]==1){
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
		}
		return;
	}
	if(val==1){
		if(arr[i][j]==1){
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
		}
		if(arr[i][j+1]==1){
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
		}
		if(arr[i+1][j]==1){
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
		}
		if(arr[i+1][j+1]==1){
			ans.pb({i+1, j+1});
			ans.pb({i+1, j});
			ans.pb({i, j+1});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i+1, j});
			ans.pb({i+1, j+1});
			ans.pb({i, j});
			ans.pb({i, j+1});
		}
		return;
	}
}

main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0; i<n; i++){
			string st;
			cin>>st;
			for(int j=0; j<m; j++){
				arr[i][j]=st[j]-'0';
			}
		}
		if(n%2==0 && m%2==0){
			
			for(int i=0; i<n; i=i+2){
				for(int j=0; j<m; j=j+2){
					
					f(i, j);
					
				}
			}
			
			
		}
		else if(n%2==1 && m%2==0){
			for(int i=0; i<m-1; i++){
				if(arr[n-1][i]==1){
					ans.pb({n-1, i});
					ans.pb({n-2, i});
					ans.pb({n-2, i+1});
					f2(n-1, i);
					f2(n-2, i);
					f2(n-2, i+1);
				}
			}
			if(arr[n-1][m-1]==1){
				ans.pb({n-1, m-1});
				ans.pb({n-2, m-1});
				ans.pb({n-2, m-2});
				f2(n-1, m-1);
				f2(n-2, m-1);
				f2(n-2, m-2);
			}
			for(int i=0; i+1<n; i=i+2){
				for(int j=0; j+1<m; j=j+2){
					f(i, j);
				}
			}
		}
		else if(m%2==1 && n%2==0){
			for(int i=0; i<n-1; i++){
				if(arr[i][m-1]==1){
					ans.pb({i, m-1});
					ans.pb({i, m-2});
					ans.pb({i+1, m-2});
					f2(i, m-1);
					f2(i, m-2);
					f2(i+1, m-2);
				}
				
			}
			if(arr[n-1][m-1]==1){
				ans.pb({n-1, m-1});
				ans.pb({n-1, m-2});
				ans.pb({n-2, m-2});
				f2(n-1, m-1);
				f2(n-1, m-2);
				f2(n-2, m-2);
			}
			for(int i=0; i+1<n; i=i+2){
				for(int j=0; j+1<m; j=j+2){
					f(i, j);
				}
			}
		}
		else{
			for(int i=0; i<n-1; i++){
				if(arr[i][m-1]==1){
					ans.pb({i, m-1});
					ans.pb({i, m-2});
					ans.pb({i+1, m-2});
					f2(i, m-1);
					f2(i, m-2);
					f2(i+1, m-2);
				}
			}
			if(arr[n-1][m-1]==1){
				ans.pb({n-1, m-1});
				ans.pb({n-1, m-2});
				ans.pb({n-2, m-2});
				f2(n-1, m-1);
				f2(n-1, m-2);
				f2(n-2, m-2);
				
			}
			for(int i=0; i<m-2; i++){
				if(arr[n-1][i]==1){
					ans.pb({n-1, i});
					ans.pb({n-2, i});
					ans.pb({n-2, i+1});
					f2(n-1, i);
					f2(n-2, i);
					f2(n-2, i+1);
				}
			}
			if(arr[n-1][m-2]==1){
				ans.pb({n-1, m-2});
				ans.pb({n-2, m-2});
				ans.pb({n-2, m-3});
				f2(n-1, m-2);
				f2(n-2, m-2);
				f2(n-2, m-3);
			}
			for(int i=0; i+1<n; i=i+2){
				for(int j=0; j+1<m; j=j+2){
					f(i, j);
				}
			}
		}
		
		int sz=ans.size();
		cout<<sz/3<<endl;
		for(int i=0; i<ans.size(); i=i+3){
			for(int j=i; j<i+3; j++){
				cout<<ans[j].f+1<<" "<<ans[j].s+1<<" ";
			}
			cout<<endl;
		}
		ans.clear();
	}
	
	return 0;
}