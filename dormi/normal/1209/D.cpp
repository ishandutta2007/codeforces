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

pii disjoint[(int)1e5+1];
int find(int a){
	if(disjoint[a].first==a)return a;
	return disjoint[a].first=find(disjoint[a].first);
}
void unio(int a, int b){
	int ap=find(a);
	int bp=find(b);
	if(disjoint[ap].second<disjoint[bp].second)swap(ap,bp);
	disjoint[bp].first=ap;
	disjoint[ap].second+=disjoint[bp].second;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
	int n,k;
	sc(n,k);
	for(int i=1;i<=n;i++)disjoint[i]={i,1};
	pii arr[k];
	int unhap=0;
	for(int i=0;i<k;i++){
		sc(arr[i].first,arr[i].second);
		if(find(arr[i].first)==find(arr[i].second))unhap+=1;
		else unio(arr[i].first,arr[i].second);
	}
	pr(unhap);
	return 0;
}
//sample 2: 2 1 3 5 4