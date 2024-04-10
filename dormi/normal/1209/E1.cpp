#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
void sc(){}
template<typename T,typename... Args>
void sc(T& a, Args&... args) {cin>>a,sc(args...);}
template<typename T>
void pr(T a){cout<<a;}
template<typename T,typename... Args>
void pr(T a, Args... args) {cout<<a<<" ",pr(args...);}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int t;
	sc(t);
	int combos[256][4];
	int counter=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				for(int l=0;l<4;l++){
					combos[counter][0]=i;
					combos[counter][1]=j;
					combos[counter][2]=k;
					combos[counter][3]=l;
					counter++;
				}
			}
		}
	}
	while(t--){
		int n,m;
		sc(n,m);
		map<int,vector<pii>,greater<int>> nums;
		int a;
		priority_queue<int> q;
		vector<int> col[m];
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				sc(a);
				nums[a].push_back({i,j});
				q.push(a);
				col[j].push_back(a);
			}
		}
		if(n<=3){
			int sum=0;
			while(n--){
				sum+=q.top();
				q.pop();
			}
			pr(sum);
			pr("\n");
			continue;
		}
		set<int> cols;
		for(auto x:nums){
			bool done=false;
			for(auto y:x.second){
				cols.insert(y.second);
				if(cols.size()==4){
					done=true;
					break;
				}
			}
			if(done)break;
		}
		vector<int> usecol;
		for(int x:cols){
			usecol.push_back(x);
		}
		int ans=0;
		for(int i=0;i<256;i++){
			int mas[4]={0,0,0,0};
			for(int j=0;j<usecol.size();j++){
				for(int k=0;k<4;k++){
					mas[(k+combos[i][j])%4]=max(mas[(k+combos[i][j])%4],col[usecol[j]][k]);
				}
			}
			int sum=0;
			for(int i=0;i<4;i++){
				sum+=mas[i];
			}
			ans=max(ans,sum);
		}
		pr(ans);
		pr("\n");
	}
    return 0;
}