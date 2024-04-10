#include <bits/stdc++.h>
using namespace std;
struct pa{
	int am, ind;
	pa(int a=0, int b=0):am(a),ind(b){}
	bool operator<(const pa& rhs) const{
		return am<rhs.am;
	}
};
int BIT[200001];
int n,m;
int start(int a){
	int sum=0;
	while(a>0){
		sum+=BIT[a];
		a-=a&-a;
	}
	return sum;
}
void update(int loc, int num){
	while(loc<=n){
		BIT[loc]+=num;
		loc+=loc&-loc;
	}
}
int BITam[200001];
int startam(int a){
	int sum=0;
	while(a>0){
		sum+=BITam[a];
		a-=a&-a;
	}
	return sum;
}
void updateam(int loc, int num){
	while(loc<=n){
		BITam[loc]+=num;
		loc+=loc&-loc;
	}
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    pa arr[n+1];
    pa actual[n+1];
    int truind[n+1];
    int in;
    for(int i=1;i<=n;i++){
    	cin>>in;
    	arr[i]=pa(in,i);
    	actual[i]=pa(in,i);
    }
    sort(arr,arr+n);
    int te=n;
    for(int i=1;i<=n;i++){
		truind[arr[i].ind]=te--;
    }
    int tot=0;
    for(int i=1;i<=n;i++){
    	tot+=actual[i].am;
    	int over=tot-m;
    	if(over<=0){
    		printf("0 ");
    	}
    	else{
    		int lo=1;
    		int ri=n;
    		while(lo!=ri){
    			int mid=(lo+ri)/2;
    			if(start(mid)>=over){
    				ri=mid;
    			}
    			else{
    				lo=mid+1;
    			}
    		}
    		printf("%d ",startam(lo));
    	}
    	update(truind[i],actual[i].am);
	    updateam(truind[i],1);
    }
    return 0;
}