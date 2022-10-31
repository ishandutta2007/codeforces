#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;cin>>t;
    while(t--){
        int x;cin>>x;
        int mn=1e9+2,cnt=0;
        for(int i=1;i<=x;i++){
            int y;cin>>y;
            if(y&1)continue;
            cnt++;
            mn=min(mn,y&-y);
        }
        if(cnt==x){
			--cnt;
        	while(!(mn&1))cnt++,mn>>=1;
        }
        cout<<cnt<<endl;
    }
}