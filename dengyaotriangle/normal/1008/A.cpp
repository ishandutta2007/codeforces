#include<bits/stdc++.h>

using namespace std;

const int maxn=105;

bool isv(char n){
	return n=='a'||n=='o'||n=='u'||n=='i'||n=='e';
}

int main(){
	bool ans=1;
	char x[maxn];
	int l=0;
	cin>>x;
	while(x[l])l++;
	x[l]='?';
	for(int i=0;i<l;i++){
		if(!(isv(x[i])||x[i]=='n')){
			if(!isv(x[i+1])) ans=0;
		}
	}
	if(ans) cout<<"YES";
	else cout<<"NO";
	return 0;
}