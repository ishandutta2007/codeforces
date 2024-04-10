#include <iostream>
#include <string>
#include <cstdio>
#include <vector>

using namespace std;

string s;
string ans;
int m;
vector <int> K[30];
bool B[101010];

int main()
{
	cin.sync_with_stdio(false);
	
	cin>>m>>s;
	int i,j,k,_k,cnt;
	bool ff;
	
	for(i=0;i<26;i++) K[i].push_back(-12345678);
	
	for(i=0;i<s.size();i++){
		K[s[i]-'a'].push_back(i);
	}
	
	for(i=0;i<26;i++){
		for(cnt=0,k=0,ff=0,j=0;j<s.size()-m+1;j++){
			if(B[j] == 0){
				_k = k;
				if(j+m <= K[i][k] || j > K[i][k]){
					while(k+1 < K[i].size() && j+m > K[i][k+1]) k++;
				}
				//printf("%d %d %d\n",i,k,K[i][k]);
				if(j+m <= K[i][k] || j > K[i][k]) ff=1;
				else{
					B[j] = 1;
					if(_k != k) cnt++;
				}
			}
		}
		
//		for(j=0;j<s.size();j++) printf("%d ",B[j]);
//		printf("\n");
		
		if(ff) cnt=K[i].size()-1;
		for(j=0;j<cnt;j++) ans+=('a'+i);
	}
	
	cout<<ans;
	
	return 0;
}