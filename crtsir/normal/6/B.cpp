#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
char c,x[100][100];
vector<pair<int,int> >s[26]; 
int main(){
	cin>>n>>m>>c;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++){
			cin>>x[i][j];
			if(isalpha(x[i][j]))
				s[x[i][j]-'A'].push_back(make_pair(i,j));
		}
	for(char xx='A';xx<='Z';xx++)
		if(xx!=c){
			bool can=0;
			for(int i=0;i<s[c-'A'].size();i++)
				for(int j=0;j<s[xx-'A'].size();j++)
					if(fabs(s[c-'A'][i].first-s[xx-'A'][j].first)+fabs(s[c-'A'][i].second-s[xx-'A'][j].second)<2)
						can=1;
			ans+=can;
		}
	cout<<ans;
}