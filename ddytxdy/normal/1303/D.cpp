#include<bits/stdc++.h>
#define LL long long
using namespace std;
int T,m,cnt[60],ans;LL n,sum;
void solve(){
    cin>>n>>m;sum=ans=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=1,x,num;i<=m;i++){
        scanf("%d",&x);num=-1;sum+=x;
        while(x)num++,x>>=1;
        cnt[num]++;
    }
    if(sum<n){puts("-1");return;}
    for(int i=0;i<60;i++){
    	if(n>>i&1){
    		if(!cnt[i]){
            	int j;
            	for(j=i+1;;j++)if(cnt[j])break;
            	cnt[j]--;
            	for(int k=i;k<j;k++)cnt[k]++;
            	ans+=j-i;
        	}
        	cnt[i]--;
		}
		cnt[i+1]+=cnt[i]/2;
	}
    cout<<ans<<endl;
}
int main(){
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}