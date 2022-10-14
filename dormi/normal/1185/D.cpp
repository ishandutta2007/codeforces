#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
struct pa{
	int am, loc;
	pa(int a=0, int b=0):am(a),loc(b){}
	bool operator<(const pa& rhs){
		return am<rhs.am;
	}
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    pa arr[n];
    int in;
    for(int i=0;i<n;i++){
    	cin>>in;
    	arr[i]=pa(in,i);
    }
    sort(arr,arr+n);
    int diff[n];
    int secdiff[n];
    int firdiff=-1;
    int sediff=-1;
	int tridiff=-1;
    int firam=0;
    int secam=0;
	int tricam=0;
	diff[0]=arr[1].am-arr[0].am;
	firdiff=diff[0];
	firam+=1;
	vector<pa> filoc;
	vector<pa> seloc;
	vector<pa> triloc;
	filoc.push_back(pa(0,arr[0].loc));
    for(int i=1;i<n-1;i++){
    	diff[i]=arr[i+1].am-arr[i].am;
    	if(diff[i]==firdiff){
    		firam+=1;
    		filoc.push_back(pa(i,arr[i].loc));
    	}
    	else if(diff[i]==sediff){
		    seloc.push_back(pa(i,arr[i].loc));
    		secam+=1;
    	}
    	else if(sediff==-1){
		    seloc.push_back(pa(i,arr[i].loc));
    		sediff=diff[i];
    		secam+=1;
    	}
	    else if(diff[i]==tridiff){
		    triloc.push_back(pa(i,arr[i].loc));
		    tricam+=1;
	    }
	    else if(tridiff==-1){
		    triloc.push_back(pa(i,arr[i].loc));
		    tridiff=diff[i];
		    tricam+=1;
	    }
    }
    if(secam>firam){
    	swap(firam,secam);
    	swap(firdiff,sediff);
    	filoc.swap(seloc);
    }
	if(tricam>firam){
		swap(firam,tricam);
		swap(firdiff,tridiff);
		filoc.swap(triloc);
	}
    if(firam==n-1){
    	printf("%d\n",arr[0].loc+1);
    	return 0;
    }
    if(firam<n-3){
    	printf("-1\n");
    	return 0;
    }
    if(firam==n-2){
    	if(tricam){
    		swap(secam,tricam);
    		swap(sediff,tridiff);
    		seloc.swap(triloc);
    	}
    	if(sediff==0){
    		printf("%d\n",seloc.front().loc+1);
    		return 0;
    	}
    	if(seloc.front().am==0||seloc.front().am==n-2){
    		if(seloc.front().am==n-2){
    			printf("%d\n",arr[n-1].loc+1);
    		}
    		else {
			    printf("%d\n", seloc.front().loc + 1);
		    }
		    return 0;
    	}
    	printf("-1\n");
    	return 0;
    }
    if(secam<tricam){
	    swap(secam,tricam);
	    swap(sediff,tridiff);
	    seloc.swap(triloc);
    }
    if(secam==2){
    	if(abs(seloc[0].am-seloc[1].am)!=1){
    		printf("-1\n");
    		return 0;
    	}
    	if(sediff*2==firdiff){
    		if(seloc[0].am<seloc[1].am)swap(seloc[0],seloc[1]);
    		printf("%d\n",seloc[0].loc+1);
    		return 0;
    	}
	    printf("-1\n");
	    return 0;
    }
	if(firam==1){
		if(sediff+tridiff==firdiff&&abs(seloc[0].am-triloc[0].am)==1){
			if(seloc[0].am<triloc[0].am)swap(seloc[0],triloc[0]);
			printf("%d\n",seloc[0].loc+1);
			return 0;
		}
		if(sediff+firdiff==tridiff&&abs(seloc[0].am-filoc[0].am)==1){
			if(seloc[0].am<filoc[0].am)swap(seloc[0],filoc[0]);
			printf("%d\n",seloc[0].loc+1);
			return 0;
		}
		if(tridiff+firdiff==sediff&&abs(triloc[0].am-filoc[0].am)==1){
			if(triloc[0].am<filoc[0].am)swap(triloc[0],filoc[0]);
			printf("%d\n",triloc[0].loc+1);
			return 0;
		}
	}
	if(abs(seloc[0].am-triloc[0].am)!=1){
		printf("-1\n");
		return 0;
	}
	if(sediff+tridiff==firdiff){
		if(seloc[0].am<triloc[0].am)swap(seloc[0],triloc[0]);
		printf("%d\n",seloc[0].loc+1);
		return 0;
	}
	printf("-1\n");
    return 0;
}