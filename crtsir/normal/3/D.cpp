#include<bits/stdc++.h>
using namespace std;
long long a[50003],b[50003],ba,ans;
bool c[50003];
priority_queue<pair<int,int> >q;
int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]=='?')cin>>a[i]>>b[i],c[i]=1,s[i]=')',ans+=b[i];
	for(int i=0;i<s.size();i++){
		if(c[i])q.push(make_pair(b[i]-a[i],i));
		ba+=s[i]=='('?1:-1;
		if(ba<0){
			if(q.size()==0){
				cout<<-1;
				return 0;
			}
			ba+=2,s[q.top().second]='(',ans-=q.top().first,q.pop();
		}
	}
	if(ba){
		cout<<-1;
		return 0;
	}
	cout<<ans<<endl;
	cout<<s;
}