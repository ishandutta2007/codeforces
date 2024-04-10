#include<bits/stdc++.h>
using namespace std;

const int maxn=2005;

int n,m;
struct h{
	int i;
	int p;
	int f;
};
struct pr{
	int a,b;
	int av,bv;
};

bool cpr(pr a,pr b){
	return a.av>b.av;
}
pr p[maxn];
h s[maxn];
bool vis[maxn];
bool vm[maxn];
int mstc=-1;

void rad(){
	int tmp;
	cin>>tmp;
	vis[tmp]=1;
	if(s[tmp].f!=0){
		if(!vis[s[tmp].f])mstc=s[tmp].f;
		vis[tmp]=1;
		for(int i=1;i<=m;i++){
			if(p[i].a==tmp||p[i].b==tmp&&(!vm[i])) vm[i]=1;
		}
		return;
	}
	vis[tmp]=1;
}
void dis(){
	if(mstc!=-1){
		cout<<mstc<<endl;
		vis[mstc]=1;
		mstc=-1;
		fflush(stdout);
		return;
	}else{
		bool amg=1;
		for(int i=1;i<=m;i++) if(!vm[i]) amg=0;
		if(amg){
			int maxx=0-1000,maxi;
			for(int i=1;i<=n+n;i++){
				if(!vis[i]){
					if(s[i].p>maxx){
						maxx=s[i].p;
						maxi=i;
					}
				}
			}
			cout<<maxi<<endl;
			vis[maxi]=1;
			
			fflush(stdout);
		}else{
			int li=0;
			for(int i=1;i<=m;i++){
				if(!vm[i]){
					li=i;
					break;
				}
			}
			vm[li]=1;
			vis[p[li].a]=1;
			cout<<p[li].a<<endl;
			fflush(stdout);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n+n;i++) {
		s[i].i=i;
		cin>>s[i].p;
	}
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		s[a].f=b;
		s[b].f=a;
		p[i].a=a;
		p[i].b=b;
		p[i].av=s[a].p;
		p[i].bv=s[b].p;
		if(p[i].av<p[i].bv){
			swap(p[i].av,p[i].bv);
			swap(p[i].a,p[i].b);
		}
	}
	int t;
	cin>>t;
	sort(p+1,p+1+m,cpr);
	for(int i=1;i<=n;i++){
		if(t%2){
			dis();
			rad();
		}else{
			rad();
			dis();
		}
	}
	return 0;
}