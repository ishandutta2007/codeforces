//starusc
#include<bits/stdc++.h>
using namespace std;
#define O(x) cerr<<(x)<<" : "<<#x<<"\n"
inline int read(){
	int x=0,f=1,c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return f==1?x:-x;
}
const int N=2e5+4,B=600;
vector<int>vec[B+4];
set<pair<int,int> >s;
int n,Q,cou,ans,ax[N],ay[N],w[N],st[N];
int main(){
	n=read();Q=read();
	for(int i=2;i<=B;i++)vec[i].resize(i);
	for(int i=1;i<=n;i++){
		ax[i]=read();ay[i]=read();	
	}
	for(int t=1,op,x;t<=Q;t++){
		op=read();x=read();
		if(op==1){//add
			if(ax[x]+ay[x]>B){
				w[x]=0;
				s.insert(make_pair(st[x]=t+ax[x],x));	
			}
			else{
				w[x]=t;
				for(int i=1,p=(t+ax[x])%(ax[x]+ay[x]);i<=ay[x];i++){
					++vec[ax[x]+ay[x]][p];
//					cerr<<ax[x]+ay[x]<<" "<<p<<" add\n";
					++p;
					if(p==ax[x]+ay[x])p=0;
				}
			}
		}
		else{
			if(ax[x]+ay[x]>B){
				if(w[x])--cou;
				s.erase(make_pair(st[x],x));
			}
			else{
				for(int i=1,p=(w[x]+ax[x])%(ax[x]+ay[x]);i<=ay[x];i++){
					--vec[ax[x]+ay[x]][p];
//					cerr<<ax[x]+ay[x]<<" "<<p<<" dec\n";
					++p;
					if(p==ax[x]+ay[x])p=0;
				}
			}
		}
		while(!s.empty()&&(*s.begin()).first==t){
			x=(*s.begin()).second;s.erase(s.begin());
			w[x]^=1;
			if(w[x]){
				++cou;
				s.insert(make_pair(st[x]=t+ay[x],x));	
			}
			else{
				--cou;
				s.insert(make_pair(st[x]=t+ax[x],x));	
			}
		}
		ans=cou;
		for(int i=2;i<=B;i++)ans+=vec[i][t%i];
		cout<<ans<<"\n";
	}
	return (0-0);
}