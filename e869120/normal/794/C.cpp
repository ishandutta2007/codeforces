#include<bits/stdc++.h>
using namespace std;
string S,T;int n,a[26],b[26],c[300000],L,R;
int main(){
	cin>>S>>T;n=S.size();R=n-1;
	for(int i=0;i<n;i++){a[S[i]-'a']++;b[T[i]-'a']++;}
	for(int i=0;i<n;i++){
		if(i%2==0){
			int minx1=26;for(int j=0;j<26;j++){if(a[j]>=1)minx1=min(minx1,j);}
			int minx2=-1;for(int j=0;j<26;j++){if(b[j]>=1)minx2=max(minx2,j);}
			if(minx1<minx2){c[L]=minx1;a[minx1]--;L++;}
			else{int rem=((n+1)/2)-(i/2+1)+1;for(int j=0;j<26;j++){rem-=a[j];if(rem<=0){c[R]=j;a[j]--;R--;break;}}}
		}
		if(i%2==1){
			int minx2=26;for(int j=0;j<26;j++){if(a[j]>=1)minx2=min(minx2,j);}
			int minx1=-1;for(int j=0;j<26;j++){if(b[j]>=1)minx1=max(minx1,j);}
			if(minx1>minx2){c[L]=minx1;b[minx1]--;L++;}
			else{int rem=(n/2)-(i/2+1)+1;for(int j=25;j>=0;j--){rem-=b[j];if(rem<=0){c[R]=j;b[j]--;R--;break;}}}
		}
	}
	for(int i=0;i<n;i++){cout<<(char)('a'+c[i]);}cout<<endl;
	return 0;
}