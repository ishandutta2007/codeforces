#include<stdio.h>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
#define R register int
#define P pair<int,int>
#define I inline
#define N 20001
set<int>G[N],Leaf[N];
int ans[N];
I void SolveFlower(set<P>&S1,set<P>&S2){
	int n=S1.size(),a,b,c;
	bool tag=false;
	if(S1.rbegin()->first!=n-3){
		S1.swap(S2);
		tag=true;
	}
	a=S1.rbegin()->second;
	b=next(S1.rbegin())->second;
	c=*Leaf[b].begin();
	ans[c]=S2.rbegin()->second;
	ans[a]=*Leaf[ans[c]].begin();
	for(auto T:S2){
		if(G[ans[c]].count(T.second)==0){
			ans[b]=T.second;
			break;
		}
	}
	auto T2=S2.begin();
	for(auto T:S1){
		if(ans[T.second]==0){
			while(T2->second==ans[a]||T2->second==ans[c]||T2->second==ans[b]){
				T2++;
			}
			ans[T.second]=T2->second;
			T2++;
		}
	}
	if(tag==true){
		for(auto T:S1){
			ans[ans[T.second]]=T.second;
		}
	}
}
I void SolveSmall(set<P>&S1,set<P>&S2){
	vector<int>A,B,C;
	for(auto T:S1){
		A.push_back(T.second);
	}
	for(auto T:S2){
		B.push_back(T.second);
	}
	int n=A.size();
	for(int i=0;i!=n;i++){
		C.push_back(i);
	}
	do{
		bool tag=true;
		map<int,int>Q;
		for(R i=0;i!=n;i++){
			Q[A[C[i]]]=B[i];
		}
		for(R i=0;i!=n;i++){
			for(int T:G[A[C[i]]]){
				if(G[B[i]].count(Q[T])!=0){
					tag=false;
					goto Fail;
				}
			}
		}
		Fail:;
		if(tag==true){
			for(R i=0;i!=n;i++){
				ans[A[C[i]]]=B[i];
			}
			break;
		}
	}while(next_permutation(C.begin(),C.end()));
}
I void Delete(set<P>&S,int x){
	int y=*G[x].begin();
	S.erase(make_pair(0,x));
	S.erase(make_pair(Leaf[y].size(),y));
	Leaf[y].erase(x);
	S.insert(make_pair(Leaf[y].size(),y));
	G[y].erase(x);
	if(G[y].size()==1){
		x=*G[y].begin();
		S.erase(make_pair(Leaf[x].size(),x));
		Leaf[x].insert(y);
		S.insert(make_pair(Leaf[x].size(),x));
	}
}
I void Solve(set<P>&S1,set<P>&S2){
	int n=S1.size();
	if(S1.rbegin()->first==n-3||S2.rbegin()->first==n-3){
		return SolveFlower(S1,S2);
	}
	if(n<7){
		return SolveSmall(S1,S2);
	}
	int A0=S1.rbegin()->second,A1,B0=next(S1.rbegin())->second,B1,C0=S2.rbegin()->second,C1,D0=next(S2.rbegin())->second,D1;
	A1=*Leaf[A0].begin();
	B1=*Leaf[B0].begin();
	C1=*Leaf[C0].begin();
	D1=*Leaf[D0].begin();
	Delete(S1,A1);
	Delete(S1,B1);
	Delete(S2,C1);
	Delete(S2,D1);
	Solve(S1,S2);
	if(G[C1].count(ans[A0])==0&&G[D1].count(ans[B0])==0){
		ans[A1]=C1;
		ans[B1]=D1;
	}else{
		ans[A1]=D1;
		ans[B1]=C1;
	}
}
int main(){
	int n,x,y,t;
	//scanf("%d",&t);
	t=1;
	for(R i=0;i!=t;i++){
		scanf("%d",&n);
		for(R j=n<<1;j!=0;j--){
			set<int>().swap(G[j]);
			set<int>().swap(Leaf[j]);
		}
		for(R j=n<<1;j!=2;j--){
			scanf("%d%d",&x,&y);
			G[x].insert(y);
			G[y].insert(x);
		}
		set<P>S1,S2;
		for(int j=1;j<=n<<1;j++){
			if(G[j].size()==n-1){
				puts("No");
				goto End;
			}
			if(G[j].size()==1){
				Leaf[*G[j].begin()].insert(j);
			}
		}
		for(int j=1;j<=n;j++){
			S1.insert(make_pair(Leaf[j].size(),j));
		}
		for(R j=1;j<=n;j++){
			S2.insert(make_pair(Leaf[j+n].size(),j+n));
		}
		Solve(S1,S2);
		puts("Yes");
		for(R j=1;j<=n;j++){
			printf("%d ",ans[j]);
		}
		puts("");
		End:;
	}
	return 0;
}