#include<iostream>
#include<set>
using namespace std;
#define R register int
#define L long long
inline bool DFS(L sum,multiset<L>&S){
	if(S.find(sum)!=S.end()){
		S.erase(S.find(sum));
		return true;
	}
	if(sum<*S.begin()){
		return false;
	}
	L a=sum>>1,b;
	b=sum-a;
	if(DFS(a,S)==false){
		return false;
	}
	return DFS(b,S);
}
inline void Solve(){
	int n,x;
	cin>>n;
	multiset<L>S;
	L sum=0;
	for(R i=0;i!=n;i++){
		cin>>x;
		S.insert(x);
		sum+=x;
	}
	if(DFS(sum,S)==true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}