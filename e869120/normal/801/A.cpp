#include<bits/stdc++.h>
using namespace std;
string S;
int hantei(string U){
	int cnt=0;
	for(int i=0;i<U.size()-1;i++){
		if(U[i]=='V' && U[i+1]=='K')cnt++;
	}
	return cnt;
}
int main(){
	cin>>S;int maxn=hantei(S);
	for(int i=0;i<S.size();i++){
		string T=S;
		if(T[i]=='V')T[i]='K';else T[i]='V';
		maxn=max(maxn,hantei(T));
	}
	cout<<maxn<<endl;
	return 0;
}