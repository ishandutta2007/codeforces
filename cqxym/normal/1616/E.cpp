#include<iostream>
#include<algorithm>
#include<deque>
using namespace std;
#define R register int
#define I inline
int C[26][100001];
deque<int>A[26];
I void Modify(int x,const int d,const int t,const int n){
	for(R i=x+1;i<=n;i+=i&-i){
		C[t][i]+=d;
	}
}
I int GetSum(int x,const int d){
	int res=0;
	for(R i=x+1;i!=0;i&=i-1){
		res+=C[d][i];
	}
	return res;
}
I void Solve(){
	int n;
	long long ans=999999999999999,cur=0;
	cin>>n;
	for(R i=0;i!=26;i++){
		deque<int>().swap(A[i]);
		for(R j=1;j<=n;j++){
			C[i][j]=0;
		}
	}
	string s,t,g;
	cin>>s>>t;
	g=s;
	sort(g.begin(),g.end());
	if(g>=t){
		cout<<-1<<endl;
		return;
	}
	for(int i=0;i!=n;i++){
		int x=s[i]-'a';
		A[x].push_back(i);
		Modify(i,1,x,n);
	}
	for(R i=0;i!=n;i++){
		int pos=n;
		char c;
		for(R j=0;j!=26;j++){
			if(A[j].empty()==false&&pos>A[j].front()){
				pos=A[j].front();
				c=j+'a';
			}
		}
		//printf("I%d %c\n",i,c);
		if(c<t[i]){
			if(cur<ans){
				ans=cur;
			}
			break;
		}
		int x=t[i]-'a',p=n,sum=0;
		for(R j=0;j!=x;j++){
			if(A[j].empty()==false&&A[j].front()<p){
				p=A[j].front();
			}
		}
		if(p!=n){
			//printf("P%d\n",p);
			for(R j=0;j!=26;j++){
				sum+=GetSum(p-1,j);
			}
			//printf("S%d\n",sum);
			if(cur+sum<ans){
				ans=cur+sum;
			}
		}
		if(A[x].empty()==true){
			break;
		}
		p=A[x].front();
		Modify(p,-1,x,n);
		A[x].pop_front();
		sum=0;
		for(R j=0;j!=26;j++){
			sum+=GetSum(p,j);
		}
		//printf("L%d %d %d\n",p,sum,cur);
		cur+=sum;
	}
	cout<<ans<<endl;
}
int main(){
	int t;
	cin>>t;
	for(R i=0;i!=t;i++){
		Solve();
	}
	return 0;
}