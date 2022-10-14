#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
const int b=0.6*(double)sqrt(500000);
lli pre[b][b];
lli arr[500001];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int q;
    cin>>q;
    while(q--){
    	lli t,x,y;
    	cin>>t>>x>>y;
		if(t==1){
			arr[x]+=y;
			for(int i=1;i<b;i++){
				pre[i][x%i]+=y;
			}
		}
		else{
			if(x<b)printf("%lli\n",pre[x][y]);
			else{
				lli ans=0;
				for(int i=y;i<=500000;i+=x){
					ans+=arr[i];
				}
				printf("%lli\n",ans);
			}
		}
    }
    return 0;
}