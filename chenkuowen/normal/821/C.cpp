#include<cstdio>
#include<algorithm>
#include<stack>
#include<set>
using namespace std;
set<int> a;
stack<int> stk;
char s[60];
int main(){
	int n,poi=0,ans=0; scanf("%d",&n);
	for(int i=1;i<=n+n;++i){
		scanf("%s",s);
		switch(s[0]){
			case 'a':{
				int key; scanf("%d",&key);
				stk.push(key);
				break;
			}
			case 'r':{
				++poi;
				if(stk.empty()) a.erase(a.begin());
				else if(stk.top()!=poi){
					while(!stk.empty()) 
						a.insert(stk.top()),stk.pop();
					a.erase(a.begin());
					++ans;
				}else stk.pop();
				break;
			}
		}
	}
	printf("%d",ans);
	return 0;
}