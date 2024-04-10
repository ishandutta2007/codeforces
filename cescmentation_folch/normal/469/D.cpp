#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef vector<int> VI;
typedef map<int, int> MI;

MI M;
MI P;
VI V;
VI T;

//gala

int rep(int x){
	if(V[x] == x) return x;
	return V[x] = rep(V[x]);
}

int main(){
	int n,a,b;
	cin>>n>>a>>b;
	V = VI(n);
	T = VI(n);
	VI K(n,0);
	for(int i = 0;i < n;++i){
		cin>>T[i];
		M[T[i]] = i;
		V[i] = i;
	}
	for(int i = 0;i < n;++i){
		if(M.find(a-T[i]) != M.end()){
			V[rep(M[a-T[i]])] = rep(i);
			K[i] |= 1;
		}
		if(M.find(b-T[i]) != M.end()){
			V[rep(M[b-T[i]])] = rep(i);
			K[i] |= 2;
		}
	}
	VI S(n,3);
	for(int i = 0;i < n;++i){
		S[rep(i)] &= K[i];
	}
	bool xec = true;
	for(int i = 0;i < n;++i){
		if(S[i] == 0) xec = false;
	}
	if(xec){
		cout<<"YES"<<endl;
		for(int i = 0;i < n;++i){
			if(i > 0) cout<<" ";
			cout<<(S[rep(i)]>>1);
		}
		cout<<endl;
	}
	else cout<<"NO"<<endl;
}