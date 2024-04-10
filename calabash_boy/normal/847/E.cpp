#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+1000;
int bug[maxn],bird[maxn],bugtot,birdtot;
int n;
char s[maxn];
const int INF = 0x3f3f3f3f;
bool check(int T){
	int i=0,j=0;
	for (;i<birdtot&&j<bugtot;i++){
		int temp = 0;
		int now = bird[i];
		int last = bug[j];
		if (bug[j]<bird[i]){
			temp=bird[i]-bug[j];
			now = bug[j];
			j++;
			if (temp>T){
				return false;
			}
		}
		int right = now+T-temp;
		right = max(right,bird[i]);
		while (j<bugtot&&bug[j]<=right){
			j++;
		}
		while (j<bugtot&&bug[j]*2-bird[i]-last<=T){
			j++;
		}
		if (j==bugtot){
			return true;
		}
	}
	return false;
} 
bool check2(int T){
	int i=birdtot-1,j=bugtot-1;
	for (;i>=0&&j>=0;i--){
		int temp = 0;
		int now = bird[i];
		int last = bug[j];
		if (bug[j]>bird[i]){
			temp=bug[j]-bird[i];
			now = bug[j];
			j--;
			if (temp>T){
				return false;
			}
		}
		int left = now-T+temp;
		left = min(left,bird[i]);
		while (j>=0&&bug[j]>=left){
			j--;
		}
		while (j>=0&&last+bird[i]-2*bug[j]<=T){
			j--;
		}
		if (j==-1){
			return true;
		}
	}
	return false;
} 

int main(){
	scanf("%d",&n);
	getchar();
	gets(s);
	for (int i=0;i<n;i++){
		if (s[i]=='*'){
			bug[bugtot++] = i;
		}else if (s[i]=='P'){
			bird[birdtot++] =i;
		}
	}
//	sort(bug,bug+bugtot);
//	sort(bird,bird+birdtot);
	int l =0;
	int r=INF;
	while (r-l>1){
		int mid = l+r >>1;
//		cout<<l<<" "<<r<<" check "<<mid<<endl;
		if (check(mid)||check2(mid)){
			r=mid;
		}else{
			l=mid;
		}
	}
	if (check(l)||check2(l)){
		cout<<l<<endl;
	}else{
		cout<<r<<endl;
	}
	return 0;
}