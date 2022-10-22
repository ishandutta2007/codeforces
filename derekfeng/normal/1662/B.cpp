#include<bits/stdc++.h>
using namespace std;
char s[1005];
int N[3],num[26][3];
vector<pair<int,int> >v;
vector<int>C[3];
vector<pair<int,int> >ans;
int main(){
	for(int i=0;i<3;i++){
		scanf("%s",s),N[i]=strlen(s);
		for(int j=0;j<N[i];j++)num[s[j]-'A'][i]++;
	}
	for(int c=0;c<26;c++){
		int tmp=0,X=0,Y=0,Z=0;
		for(int x=0;x<=min(num[c][0],num[c][1]);x++)
			for(int y=0;y<=min(num[c][0],num[c][2]);y++)
				if(x+y<=num[c][0]){
					int z=min(num[c][1]-x,num[c][2]-y);
					if(x+y+z>tmp)tmp=x+y+z,X=x,Y=y,Z=z;
				}
		for(int i=0;i<X;i++)v.push_back({c,2});
		for(int i=0;i<Y;i++)v.push_back({c,1});
		for(int i=0;i<Z;i++)v.push_back({c,0});
		for(int i=X+Y;i<num[c][0];i++)C[0].push_back(c);
		for(int i=X+Z;i<num[c][1];i++)C[1].push_back(c);
		for(int i=Y+Z;i<num[c][2];i++)C[2].push_back(c);
	}
	for(int i=0;i<3;i++)while(v.size()>N[i]){
		if(v.back().second==2){
			C[0].push_back(v.back().first);
			C[1].push_back(v.back().first);
		}
		if(v.back().second==1){
			C[0].push_back(v.back().first);
			C[2].push_back(v.back().first);
		}
		if(v.back().second==0){
			C[1].push_back(v.back().first);
			C[2].push_back(v.back().first);
		}
		v.pop_back();
	}
	for(auto [c,t]:v)
		ans.push_back({c,C[t].back()}),C[t].pop_back();
	for(;;){
		int cnt=0;
		for(int i=0;i<3;i++)cnt+=C[i].empty();
		if(cnt==3)break;
		if(cnt==2){
			for(int i=0;i<3;i++)if(!C[i].empty()){
				ans.push_back({C[i].back(),C[i].back()});
				C[i].pop_back();break;
			}
			continue;
		}
		for(int i=0;i<3;i++){
			bool ok=1;
			for(int j=0;j<3;j++)ok&=C[i].size()<=C[j].size();
			if(!ok)continue;
			vector<int>vv;
			for(int j=0;j<3;j++)if(i!=j)
				vv.push_back(C[j].back()),C[j].pop_back();
			ans.push_back({vv[0],vv[1]});
			break;
		}
	}
	printf("%d\n",ans.size());
	for(auto [x,y]:ans)putchar(x+'A'),putchar(y+'A'),puts("");
}