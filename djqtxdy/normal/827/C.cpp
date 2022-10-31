#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <climits>
#include <string.h>
#include <stdio.h>
#define LL long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int, pii >
#define REP(i,n) for (int (i)=0;(i)<(n);(i)++)
#define vi vector<int>
#define vpi vector< pii >
#define INF 2147483647
#define big 19260817
#define pb push_back
#define mp make_pair
using namespace std;
const int Maxk=1005;
// cf IO: I64d
// atcoder IO: 
const int Maxn=100005;
const int Maxm=11;
int Bit[Maxm][Maxn][Maxm][4];
char s[Maxn];
char k[Maxm];
int n;
void add(int len,int cty,int loc,int pos,int val){
	while (pos<=n){
		Bit[len][pos][loc][cty]+=val;
		pos+=pos&-pos;
	}
}
int query(int len,int cty,int loc,int pos){
	int res=0;
	while (pos>0){
		res+=Bit[len][pos][loc][cty];
		pos-=pos&-pos;
	}
	return res;
}
int f(char c){
	if (c=='A') return 0;
	if (c=='T') return 1;
	if (c=='G') return 2;
	return 3;
}
void rshift(int len){
	char tmp=k[0];
	for (int i=0;i<len-1;i++){
		k[i]=k[i+1];
	}
	k[len-1]=tmp;
}
int main(){
	scanf("%s",s);
	n=strlen(s);
	for (int len=1;len<=10;len++){
		for (int siz=1;;siz++){
			int beg=(siz-1)*len;
			int end=beg+len-1;
			if (end>=n) break;
			for (int i=beg;i<=end;i++){
				add(len,f(s[i]),i-beg+1,siz,1);
			}
		}
	}
	int q;
	scanf("%d",&q);
	while (q--){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int loc;
			char c;
			scanf("%d %c",&loc,&c);
			loc--;
			for (int len=1;len<=10;len++){
				add(len,f(s[loc]),loc%len+1,loc/len+1,-1);
				add(len,f(c),loc%len+1,loc/len+1,1);
			}
			s[loc]=c;
		}
		else{
			int l,r;
			scanf("%d %d ",&l,&r);
			l--;
			r--;
			scanf("%s",k);
			int len=strlen(k);
			int ans=0;
			while (l%len!=0 && l<=r){
				ans+=(s[l]==k[0]);
				rshift(len);
				l++;
			}
			if (l>r){
				printf("%d\n",ans);
				continue;
			}
			while ((r+1)%len!=0 && r>=l){
				ans+=(s[r]==k[r%len]);
				r--;
			}
			if (l>r){
				printf("%d\n",ans);
				continue;
			}
			for (int i=0;i<len;i++){
				int occ=query(len,f(k[i]),i+1,r/len+1)-query(len,f(k[i]),i+1,l/len);
				ans+=occ;
			}
			printf("%d\n",ans);
		}
	}
}