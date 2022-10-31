#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
int peo[MAXN],ke[MAXN];
int k,n,p;
long long ans =0;
long long calc(int startIndex){
	long long deltaAns =0;
	for (int i=0;i<n;i++){
		int temp = ke[startIndex+i];
		if (temp>=peo[i]&&temp<=p||temp<=peo[i]&&temp>=p){
			long long ans2 = (abs(peo[i]-p));
			deltaAns=max(deltaAns,ans2);
		}else if (peo[i]>=temp&&peo[i]<=p||peo[i]>=p&&peo[i]<=temp){
			long long ans2 = abs(peo[i]-p)+2*abs(temp-peo[i]);
			deltaAns=max(deltaAns,ans2);
		}else{
			long long ans2 = abs(peo[i]-temp)+abs(temp-p);
			deltaAns = max(deltaAns,ans2);
		}
	}
	return deltaAns;
}
int main(){
	cin>>n>>k>>p;
	for (int i=0;i<n;i++){
		cin>>peo[i];
		ans+=abs(peo[i]-p);
	}
	for (int i=0;i<k;i++){
		cin>>ke[i];
	}
	sort(peo+0,peo+n);
	sort(ke+0,ke+k);
	long long ll = 0;
    long long  rr = k-n;
    while (rr>ll+2){
        int mid = (rr-ll)/3+ll;
        int mmid = (rr-ll)/3*2+ll;
        long long midAns = calc(mid);
        long long mmidAns = calc(mmid);
//        cout<<"l:"<<ll<<" r:"<<rr<<" mid:"<<mid<<" mmid:"<<mmid<<" midAns:"<<midAns<<" mmidAns"<<mmidAns<<endl;
        if (midAns<mmidAns){
            rr=mmid;
        }else{
            ll=mid;
        }
    }
    long long tempAns = 21474836470;
    for (int i=ll;i<=rr;i++){
    	tempAns = min(tempAns,calc(i));
    }
    cout<<tempAns<<endl;
    return 0;
}