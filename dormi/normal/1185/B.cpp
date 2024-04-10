#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    string a,b;
    for(int i=0;i<n;i++){
    	cin>>a>>b;
    	int l=0;
    	int r=0;
    	char te='#';
    	int am=0;
    	bool work=true;
    	while(l<a.size()&&work){
			te=a[l];
			am=1;
			while(l+1<a.size()&&a[l+1]==te){
				l+=1;
				am+=1;
			}
			while(r<b.size()&&b[r]==te){
				am-=1;
				r+=1;
			}
			if(am>0){
				printf("NO\n");
				work=false;
			}
			l+=1;
    	}
    	if(r<b.size()&&work){
    		printf("NO\n");
    	}
    	else if(work){
    		printf("YES\n");
    	}
    }
    return 0;
}