/******************
*  Author: BD747  *
******************/
#include<algorithm>
#include<iostream>
using namespace std;

string t,bg,ed;
typedef long long int64;
const int SEED=1331;
const int MAX_N=2010;
int64 POWAGAINFAQ[MAX_N];
int64 HASHITFAQ[MAX_N];

int64 getHASHITFAQ(int l,int r){
	return HASHITFAQ[r]-HASHITFAQ[l]*POWAGAINFAQ[r-l];
}

int64 calcHASHITFAQ(const string &s){
	int64 ret=0;
	for(int i=0;i<s.size();i++){
		ret=ret*SEED+s[i];
	}
	return ret;
}

int64 ss[MAX_N*MAX_N];
int cnt;

int main(){

	cin>>t>>bg>>ed;
	POWAGAINFAQ[0]=1;
	for(int i=1;i<MAX_N;i++){
		POWAGAINFAQ[i]=POWAGAINFAQ[i-1]*SEED;
	}
	HASHITFAQ[0]=0;
	for(int i=1;i<=t.size();i++){
		HASHITFAQ[i]=HASHITFAQ[i-1]*SEED+t[i-1];
	}
	int64 bh=calcHASHITFAQ(bg),eh=calcHASHITFAQ(ed);
	cnt=0;
	for(int i=0;i<t.size();i++){
		if(i+bg.size()<=t.size()){
			if(getHASHITFAQ(i,i+bg.size())==bh){
				for(int j=i;j<t.size();j++){
					if(j+ed.size()<=t.size()){
						if(getHASHITFAQ(j,j+ed.size())==eh){
							if(j+ed.size()>=i+bg.size()){
								ss[cnt++]=getHASHITFAQ(i,j+ed.size());
							}
						}
					}
				}
			}
		}
	}
	sort(ss,ss+cnt);
	cnt=unique(ss,ss+cnt)-ss;
	cout<<cnt<<endl;

	return 0;
}