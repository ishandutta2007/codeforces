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
int lastloc[200001];
int ams[200001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,q;
	sc(n,q);
	int arr[n];
	for(int i=0;i<n;i++)sc(arr[i]);
	for(int i=0;i<n;i++){
		lastloc[arr[i]]=i;
	}
	int r=-1;
	int size=0;
	set<int> vals;
	int best=0;
	int ans=0;
	for(int i=0;i<n;i++){
		size+=1;
		r=max(r,lastloc[arr[i]]);
		vals.insert(arr[i]);
		ams[arr[i]]+=1;
		best=max(best,ams[arr[i]]);
		if(r==i){
			ans+=(size-best);
			for(int x:vals)ams[x]=0;
			vals.clear();
			best=0;
			size=0;
		}
	}
	pr(ans);
    return 0;
}