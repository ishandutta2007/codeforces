#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5+100;
char opt[maxn][5];


int a[maxn];
int result[32][2];
int bas[32];
int n;
vector<pair<char,int> >ans;
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%s%d",opt[i],a+i);
	}
	bas[0]=1;
	for (int i=1;i<=9;i++){
		bas[i] = bas[i-1]*2;
	}
	for (int i=0;i<=9;i++){
		for (int j=0;j<=1;j++){
			int temp = j*bas[i];
			for (int k =1;k<=n;k++){
				int p = a[k]&bas[i];
				if (opt[k][0]=='&'){
					temp&= p;
				}else if (opt[k][0]=='|'){
					temp|=p;
				}else if (opt[k][0]=='^'){
					temp^=p;
				}
			}
			result[i][j] = (temp!=0);
		} 
	}
	int xorans =0;
	for (int i=0;i<=9;i++){
		if (result[i][0]==1&&result[i][1]==0){
			xorans +=bas[i];
		}
	}
	ans.push_back(make_pair('^',xorans));
	int andans = 1023;
	for (int i=0;i<=9;i++){
		if (result[i][0]==0&&result[i][1]==0){
			andans -= bas[i];
		}
	}
	ans.push_back(make_pair('&',andans));
	int orans = 0;
	for (int i=0;i<=9;i++){
		if (result[i][0]==1&&result[i][1]==1){
			orans += bas[i];
		}
	}
	ans.push_back(make_pair('|',orans));
	cout<<ans.size()<<endl;
	for (auto temp:ans){
		printf("%c %d\n",temp.first,temp.second);
	}
	return 0;
}