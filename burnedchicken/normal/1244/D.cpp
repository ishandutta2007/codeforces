#include <bits/stdc++.h>

#define ll long long int
#define loop(a) for(int i=0; i<a; i++)
 
using namespace std;

int main(){
	int n;
	cin >> n;
	ll a[n],b[n],c[n];
	loop(n){
		cin >> a[i];
	}
	loop(n){
		cin >> b[i];
	}
	loop(n){
		cin >> c[i];
	}
	int e[n-1][2];
	loop(n-1){
		cin >> e[i][0] >> e[i][1];
	}
	int degr[n+1];
	loop(n+1){
		degr[i]=0;
	}
	loop(n-1){
		degr[e[i][0]]++;
		degr[e[i][1]]++;
		if(degr[e[i][0]]>2){
			cout << -1 << endl;
			return 0;
		}
		if(degr[e[i][1]]>2){
			cout << -1 << endl;
			return 0;
		}
	}
	int leaf;
	loop(n){
		if(degr[i+1]==1){
			leaf=i+1;
			break;
		}
	}
	int nei[n+1][2];
	loop(n+1){
		nei[i][0]=0;
		nei[i][1]=0;
	}
	loop(n-1){
		if(nei[e[i][0]][0]>0) nei[e[i][0]][1]=e[i][1];
		else nei[e[i][0]][0]=e[i][1];
		if(nei[e[i][1]][0]>0) nei[e[i][1]][1]=e[i][0];
		else nei[e[i][1]][0]=e[i][0];
	}
	bool used[n+1];
	int tree[n];
	loop(n+1){
		used[i]=false;
	}
	loop(n){
		used[leaf]=true;
		tree[i]=leaf;
		if(used[nei[leaf][0]]) leaf=nei[leaf][1];
		else leaf=nei[leaf][0];
	}
	ll num[6];
	int cur;
	int col[n][6];
	loop(6){
		num[i]=0;
	}
	cur=1;
	loop(n){
		if(cur==1){
			num[0]=num[0]+a[tree[i]-1];
			col[tree[i]-1][0]=cur;
			cur++;
		}
		else if(cur==2){
			num[0]=num[0]+b[tree[i]-1];
			col[tree[i]-1][0]=cur;
			cur++;
		}
		else if(cur==3){
			num[0]=num[0]+c[tree[i]-1];
			col[tree[i]-1][0]=cur;
			cur=1;
		}
	}
	cur=1;
	loop(n){
		if(cur==1){
			num[1]=num[1]+a[tree[i]-1];
			col[tree[i]-1][1]=cur;
			cur=3;
		}
		else if(cur==2){
			num[1]=num[1]+b[tree[i]-1];
			col[tree[i]-1][1]=cur;
			cur--;
		}
		else if(cur==3){
			num[1]=num[1]+c[tree[i]-1];
			col[tree[i]-1][1]=cur;
			cur--;
		}
	}
	cur=2;
	loop(n){
		if(cur==1){
			num[2]=num[2]+a[tree[i]-1];
			col[tree[i]-1][2]=cur;
			cur=3;
		}
		else if(cur==2){
			num[2]=num[2]+b[tree[i]-1];
			col[tree[i]-1][2]=cur;
			cur--;
		}
		else if(cur==3){
			num[2]=num[2]+c[tree[i]-1];
			col[tree[i]-1][2]=cur;
			cur--;
		}
	}
	cur=2;
	loop(n){
		if(cur==1){
			num[3]=num[3]+a[tree[i]-1];
			col[tree[i]-1][3]=cur;
			cur++;
		}
		else if(cur==2){
			num[3]=num[3]+b[tree[i]-1];
			col[tree[i]-1][3]=cur;
			cur++;
		}
		else if(cur==3){
			num[3]=num[3]+c[tree[i]-1];
			col[tree[i]-1][3]=cur;
			cur=1;
		}
	}
	cur=3;
	loop(n){
		if(cur==1){
			num[4]=num[4]+a[tree[i]-1];
			col[tree[i]-1][4]=cur;
			cur=3;
		}
		else if(cur==2){
			num[4]=num[4]+b[tree[i]-1];
			col[tree[i]-1][4]=cur;
			cur--;
		}
		else if(cur==3){
			num[4]=num[4]+c[tree[i]-1];
			col[tree[i]-1][4]=cur;
			cur--;
		}
	}
	cur=3;
	loop(n){
		if(cur==1){
			num[5]=num[5]+a[tree[i]-1];
			col[tree[i]-1][5]=cur;
			cur++;
		}
		else if(cur==2){
			num[5]=num[5]+b[tree[i]-1];
			col[tree[i]-1][5]=cur;
			cur++;
		}
		else if(cur==3){
			num[5]=num[5]+c[tree[i]-1];
			col[tree[i]-1][5]=cur;
			cur=1;
		}
	}
	ll x=min(min(min(min(min(num[0],num[1]),num[2]),num[3]),num[4]),num[5]);
	if(num[0]==x){
		cout << num[0] << endl;
		loop(n){
			cout << col[i][0] << " ";
		}
		cout << endl;
		return 0;
	}
	if(num[1]==x){
		cout << num[1] << endl;
		loop(n){
			cout << col[i][1] << " ";
		}
		cout << endl;
		return 0;
	}
	if(num[2]==x){
		cout << num[2] << endl;
		loop(n){
			cout << col[i][2] << " ";
		}
		cout << endl;
		return 0;
	}
	if(num[3]==x){
		cout << num[3] << endl;
		loop(n){
			cout << col[i][3] << " ";
		}
		cout << endl;
		return 0;
	}
	if(num[4]==x){
		cout << num[4] << endl;
		loop(n){
			cout << col[i][4] << " ";
		}
		cout << endl;
		return 0;
	}
	if(num[5]==x){
		cout << num[5] << endl;
		loop(n){
			cout << col[i][5] << " ";
		}
		cout << endl;
		return 0;
	}
}