#include<bits/stdc++.h>
using namespace std;
int n,lst[200010],nxt[200010];
char str[200010];
int main(){
	scanf("%s",str+1);n=strlen(str+1);
	stack<int> st;
	for(int i=1;i<=n;i++){
		if(str[i]=='0') st.push(i);
		else{
			if(st.empty()){puts("-1");return 0;}
			lst[i]=st.top();nxt[st.top()]=i;
//			printf("%d %d\n",i,st.top());
			st.pop();
		}
	}
	set<int> S;
	for(int i=n;i>=1;i--){
		if(str[i]=='0') S.insert(i);
		else{
			if(S.lower_bound(i)==S.end()){puts("-1");return 0;}
			int x=*S.lower_bound(i);
			nxt[i]=x;lst[x]=i;S.erase(x);
		} 
	}
	vector<vector<int> > Ans;
	for(int i=1;i<=n;i++){
		if(lst[i]) continue;
		int x=i;vector<int> vec;vec.push_back(i);
		while(nxt[x]){x=nxt[x];vec.push_back(x);}
		Ans.push_back(vec);
	}
	printf("%d\n",(int)Ans.size());
	for(auto vec:Ans){
		printf("%d ",(int)vec.size());
		for(auto x:vec) printf("%d ",x);
		puts("");
	}
	return 0;
}