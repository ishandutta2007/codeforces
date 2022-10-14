#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    priority_queue<int> ma;
    int in;
    int tot=0;
    for(int i=1;i<=n;i++){
		cin>>in;
		tot+=in;
		int te=tot;
		int am=0;
		vector<int> pt;
		while(te>m){
			te-=ma.top();
			pt.push_back(ma.top());
			ma.pop();
			am+=1;
		}
		printf("%d ",am);
		for(int x:pt)ma.push(x);
		ma.push(in);
    }
    return 0;
}