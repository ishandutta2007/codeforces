#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
const int MAX_N=5+2e5;
char s[MAX_N],t[MAX_N];
int main(){
	int n; scanf("%d",&n);
	scanf("%s%s",s+1,t+1);
	for(int i=1;i<=n;++i)
		if(s[i]!=t[i]){
			if(s[i]=='a')
				a.push_back(i);
			else 
				b.push_back(i);
		}
	if((a.size()+b.size())%2==1) puts("-1");
	else{
		int ans=(a.size()+b.size())/2;
		if(a.size()%2==1) ++ans;
		printf("%d\n",ans);
		while(a.size()>1){
			printf("%d %d\n",a[a.size()-1],a[a.size()-2]);
			a.pop_back(); a.pop_back();
		}
		while(b.size()>1){
			printf("%d %d\n",b[b.size()-1],b[b.size()-2]);
			b.pop_back(); b.pop_back();
		}
		if(a.size()>0){
			printf("%d %d\n",a[0],a[0]);
			printf("%d %d\n",a[0],b[0]);
		}
	}
	return 0;
}