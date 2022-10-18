#include<bits/stdc++.h>

using namespace std;

const int maxn=100005;
const int maxm=300005;

int n,m;
vector<int> v[5];
long long cst[maxm];
 
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int w,t;
		cin>>w>>t;
		v[w].push_back(t); 
	}	
	for(int i=1;i<=3;i++)sort(v[i].begin(),v[i].end(),greater<int>());
	memset(cst,0xc0,sizeof(cst));
	for(int o=0;o<2;o++){
		long long sm=0;
		if(v[1].size()==0&&o==1)break;
		int cp1=o,cp2=0,mx1=v[1].size(),mx2=v[2].size();  
		if(o)sm=v[1][0];
		for(int i=o;i<=m;i+=2){
			cst[i]=sm;
			if(cp1+1>=mx1&&cp2>=mx2) break;
			if(cp1+1>=mx1) sm+=v[2][cp2],cp2++;
			else if(cp2>=mx2){
				sm+=v[1][cp1],cp1++;
				sm+=v[1][cp1],cp1++; 
			}else{
				int q1=v[1][cp1]+v[1][cp1+1],q2=v[2][cp2];
				if(q1>q2){
					cp1+=2;sm+=q1;
				}else{
					cp2++;sm+=q2; 
				} 
			}
		}
	}
	for(int i=1;i<=m;i++)cst[i]=max(cst[i],cst[i-1]); 
	long long ans=0,cur=0;
	for(int i=0;i<=v[3].size();i++){
		if(m-3*i<0)break;
		ans=max(ans,cur+cst[m-3*i]);
		if(i<v[3].size())cur+=v[3][i];
	}
	cout<<ans;
	return 0;
}