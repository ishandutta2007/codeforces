#include<bits/stdc++.h>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
void output(int a,int b){
	write(a),putchar(' '),write(b),puts("");
}
int n,mch[100004];
char c[100004];
void manacher(){
	c[0]='!';
	int mid=0,r=0;
	for (int i=1;i<=n;i++){
		if (i<=r)mch[i]=min(r-i+1,mch[2*mid-i]);
		while (c[i+mch[i]]==c[i-mch[i]])mch[i]++;
		if(i+mch[i]>r)r=i+mch[i]-1,mid=i;
	}
}
int N,z[200004];
char C[200004];
pii pre[100004];
vector<int>ed[100004];
struct PQ{
	priority_queue<int>val,del;
	void DEL(){
		while(!val.empty()&&!del.empty()&&val.top()==del.top())val.pop(),del.pop();
	}
	void PUSH(int x){
		DEL();val.push(x);
	}
	void ERASE(int x){
		DEL();del.push(x);
	}
	int TOP(){
		DEL();return val.top();
	}
	bool EMPTY(){
		DEL();return val.empty();
	}
}pq;
void Z(){
	for(int i=1;i<=n;i++)C[i]=c[i];C[n+1]='~',N=n+1;
	for(int i=n;i>0;i--)C[++N]=c[i];
	int l=0,r=0;
    for (int i=2;i<=N;i++){
        if(i>r){
            l=i,r=i;
            while(r<=N&&C[r-l+1]==C[r])r++;
            z[i]=r-l,r--;
		}else{
            if(z[i-l+1]<r-i+1)z[i]=z[i-l+1];
            else{
                l=i;
                while(r<=N&&C[r-l+1]==C[r])r++;
                z[i]=r-l,r--;
        	}
        }
    }
    pre[n+1]=mkp(0,0);
    multiset<int>mst;
	for(int i=n;i>=1;i--){
		if(z[N+1-i]){
			int len=z[N+1-i];
			ed[i-len+1].push_back(i);
			pq.PUSH(i); 
		}
		if(pq.EMPTY()) pre[i]=mkp(0,i);
		else pre[i]=mkp(pq.TOP()-i+1,pq.TOP());
		pre[i]=max(pre[i],pre[i+1]);
		for(int j=0;j<ed[i].size();j++)pq.ERASE(ed[i][j]);
	}
}
int main(){
	scanf("%s",c+1),n=strlen(c+1);
	reverse(c+1,c+1+n);
	manacher();
	Z();
	int K=0,num,ans[3],len[3];
	for(int i=1;i<=n;i++){
		int L=i-mch[i]+1,R=i+mch[i]-1;
		pii ret=pre[R+1];ret.fi=min(ret.fi,L-1);
		ret.se=ret.se-ret.fi+1;
		if(ret.fi>0){
			if(2*mch[i]-1+2*ret.fi>K){
				K=2*mch[i]-1+2*ret.fi;
				num=3;
				ans[0]=ret.fi,len[0]=ret.fi;
				ans[1]=R,len[1]=2*mch[i]-1;
				ans[2]=ret.se+ret.fi-1,len[2]=ret.fi;
			}
		}else if(2*mch[i]-1>K){
			K=2*mch[i]-1;
			num=1;
			ans[0]=R,len[0]=K;
		}
	}
	write(num),puts("");
	for(int i=num-1;i>=0;i--)output(n-ans[i]+1,len[i]);
}