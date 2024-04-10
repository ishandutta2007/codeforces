#include<bits/stdc++.h>
using namespace std;
struct team{
	string name;
	int grade,win,jin;
	bool operator<(const team b)const{
		return grade==b.grade?(win==b.win?jin>b.jin:win>b.win):grade>b.grade;
	}
};
bool cmp(team a,team b){
	return a.name<	b.name;
}
string name[60];int n;
map<string,team>m;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		cin>>name[i];
	for(int i=1;i<=n*(n-1)/2;i++){
		string g,A,B;
		int a,b;
		cin>>g;//cout<<g<<endl;
		scanf("%d:%d",&a,&b);
		for(int i=0;;i++)
			if(g[i]=='-'){
				A=g.substr(0,i),B=g.substr(i+1);
			break;
		}
		//cout<<A<<" "<<B<<endl;
		m[A].jin+=a,m[B].jin+=b;
		if(a>b)m[A].grade+=3;
		if(a<b)m[B].grade+=3;
		if(a==b)m[A].grade++,m[B].grade++;
		m[A].win+=a-b;
		m[B].win+=b-a;
	}
	team t[60];
	for(int i=1;i<=n;i++)
		t[i]=m[name[i]],t[i].name=name[i];
	sort(t+1,t+1+n);
	sort(t+1,t+1+n/2,cmp);
	for(int i=1;i<=n/2;i++){
		cout<<t[i].name<<endl;
	}
}