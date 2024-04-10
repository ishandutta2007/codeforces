#include<iostream>
#include<vector>
using namespace std;
#define R register int
int a[300001];
struct TrieNode{
	int Child[2],Id;
}t[9000000];
inline int Find(int p,const int lim,int dep,int x){
	//printf("Q%d %d %d\n",p,lim,dep);
	if(dep==-1){
		return p==0?-1:t[p].Id;
	}
	int q=x>>dep&1;
	if((lim>>dep&1)==0&&t[p].Child[q^1]!=0){
		return Find(t[p].Child[q^1],0,dep-1,0);
	}
	q^=lim>>dep&1;
	p=t[p].Child[q];
	if(p==0){
		return-1;
	}
	return Find(p,lim,dep-1,x);
}
inline bool DFS(int p,int dep,const int p2,const int d2,const int lim,vector<int>&A){
	if(dep==-1){
		int y=Find(p2,lim,d2,a[t[p].Id]);
		if(y!=-1){
			A.push_back(t[p].Id);
			A.push_back(y);
			return true;
		}
		return false;
	}
	bool tag=false;
	if(t[p].Child[0]!=0){
		tag=DFS(t[p].Child[0],dep-1,p2,d2,lim,A);
	}
	if(tag==false&&t[p].Child[1]!=0){
		tag=DFS(t[p].Child[1],dep-1,p2,d2,lim,A);
	}
	return tag;
}
inline void Solve(int p,const int lim,int dep,vector<int>&A){
	//printf("P%d %d %d\n",p,lim,dep);
	int x=lim>>dep&1;
	if(x==0){
		for(R i=0;i!=2;i++){
			if(t[p].Child[i]!=0){
				Solve(t[p].Child[i],lim,dep-1,A);
			}
		}
	}else if(DFS(t[p].Child[0],dep-1,t[p].Child[1],dep-1,lim,A)==false){
		A.push_back(Find(p,0,dep,0));
	}
}
int main(){
	int n,k,x,p,ct=1;
	cin>>n>>k;
	if(k==0){
		cout<<n<<endl;
		for(R i=1;i<=n;i++){
			cout<<i<<' ';
		}
		return 0;
	}
	for(R i=0;i!=n;i++){
		cin>>x;
		a[i+1]=x;
		p=1;
		for(R j=29;j!=-1;j--){
			int&y=t[p].Child[x>>j&1];
			if(y==0){
				ct++;
				y=ct;
			}
			p=y;
			t[p].Id=i+1;
		}
	}
	vector<int>A;
	Solve(1,k,29,A);
	if(A.size()<2){
		cout<<-1;
	}else{
		int t=0;
		for(int T:A){
			if(T!=0){
				t++;
			}
		}
		cout<<t<<endl;
		for(int T:A){
			if(T!=0){
				cout<<T<<' ';
			}
		}
	}
	return 0;
}