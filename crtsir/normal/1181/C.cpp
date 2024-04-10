#include<bits/stdc++.h>
using namespace std;
struct flag{
	char a,b,c;
	long long pos,len;
};
bool dengyu(flag a,flag b){
	if(a.a!=b.a)return 0;
	if(a.b!=b.b)return 0;
	if(a.c!=b.c)return 0;
	if(a.len!=b.len)return 0;
	if(a.pos!=b.pos)return 0;
	return 1; 
}
long long ans=0;
char c[1003][1003],tmp;
bool vis[1003][1003];
vector<flag>flags[1003];
bool find(long long thesz,flag findthing){
	long long l=0,r=flags[thesz].size()-1;
	while(l<=r){
		long long mid=(l+r)/2;
		if(dengyu(findthing,flags[thesz][mid])){vis[thesz][mid]=1;return 1;}
		if(findthing.pos>flags[thesz][mid].pos)
			l=mid+1;
		else
			r=mid-1;
	}
	return 0;
}
int main(){
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++)
	{
		tmp=getchar();
		for(long long j=0;j<m;j++)
			c[i][j]=getchar();
	}
	for(long long i=0;i<m;i++){
		long long cnt=1;
		vector<long long>pos;
		vector<pair<long long,char> >v;
		pos.push_back(0);
		for(long long j=1;j<n;j++){
			if(c[j][i]==c[j-1][i])
				cnt++;
			else
				v.push_back(make_pair(cnt,c[j-1][i])),
				pos.push_back(j),
				cnt=1;
		}
		v.push_back(make_pair(cnt,c[n-1][i]));
		for(long long j=1;j<v.size()-1;j++)
			if(v[j].first<=v[j-1].first&&v[j].first<=v[j+1].first){
				flag ttmp;
				ttmp.a=v[j-1].second;
				ttmp.b=v[j].second;
				ttmp.c=v[j+1].second;
				ttmp.len=v[j].first;
				ttmp.pos=pos[j]-v[j].first;
				flags[i].push_back(ttmp);
			}
	}
	for(long long i=0;i<m;i++){
		if(flags[i].size())
			for(long long j=0;j<flags[i].size();j++)
				if(!vis[int(i)][int(j)])
				{
					long long cnt=i+1,res=1,k;
					while(1){
						if(flags[cnt].size()==0)break;
						if(find(cnt,flags[i][j]))res++;
						else break;
						cnt++;
					}
				ans+=res*(res+1)/2;
				}
	}
	cout<<ans;
}