#include<bits/stdc++.h>
using namespace std;
int n,k;string s;
bool check(){for(int i=0;i<n-1;i++)if(s[i]=='R'&&s[i+1]=='L')return 1;return 0;}
int main(){
	cin>>n>>k>>s;int minn=0,maxn=0;string t=s;
	while(check()){
		for(int i=0;i<n-1;i++)
			if(s[i]=='R'&&s[i+1]=='L')maxn++,swap(s[i],s[i+1]),i++;
		minn++;
	}s=t;
	if(k<minn||k>maxn){cout<<-1;return 0;}
	vector<vector<int> >res,v;
	while(check()){vector<int>tmp;
		for(int i=0;i<n-1;i++)
			if(s[i]=='R'&&s[i+1]=='L')
				tmp.push_back(i),
				swap(s[i],s[i+1]),i++;
		v.push_back(tmp);
	}int del=k-minn;
	for(int i=0;i<v.size();i++)
		if(del)
			for(int j=0;j<v[i].size();j++)
				if(del!=0){
					if(j!=v[i].size()-1)del--;
					vector<int>tmp;tmp.push_back(v[i][j]);
					res.push_back(tmp);
				}else{
					vector<int>tmp;
					for(j;j<v[i].size();j++)
						tmp.push_back(v[i][j]);
					res.push_back(tmp);
				}
		else
			res.push_back(v[i]);
	for(int i=0;i<k;i++){
		printf("%d ",res[i].size());
		for(int j=0;j<res[i].size();j++)
			printf("%d ",res[i][j]+1);
		printf("\n");
	}
}